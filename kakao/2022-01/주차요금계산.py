from collections import defaultdict
import math

def change_time(time):
    h,m = map(int,time.split(":"))
    return m + h*60

def calculate_fee(time, fees):
    default_time, default_fee, unit_time, unit_fee = fees
    if time <= default_time:
        return default_fee
    return default_fee + math.ceil((time-default_time)/unit_time) * unit_fee

def solution(fees, records):
    answer = []
    car_times = defaultdict(list)
    car_fees = defaultdict(int)
    for rec in records:
        time, number, type = rec.split(" ")
        time = change_time(time)
        car_times[number].append((time, type))

    for car, lst in car_times.items():
        total_time = 0
        end = change_time("23:59")
        while lst:
            time, type = lst.pop()
            if type == "IN":
                total_time += (end - time)
            elif type == "OUT":
                end = time
        car_fees[car] = calculate_fee(total_time, fees)

    answer = [v for _,v in sorted(car_fees.items())]

    return answer

print(solution([180, 5000, 10, 600], ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]),[14600, 34400, 5000])