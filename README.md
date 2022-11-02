# Retirement
Arduino Project to track and display days until my dad retires

# Images


# Implementation
To display the current number of days left, I used unix time(number of seconds since 1970):
1. Found unix time of when my dad retired(static number), and periodically found current unix time(using wifi)
2. I subtracted the unix time of when my dad retired by the current unix time
3. I converted this number of seconds to days, and then displayed it on the 4-digit 7-segment board




