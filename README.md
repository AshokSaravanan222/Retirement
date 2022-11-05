# Retirement
Author: Ashok Saravanan

Created 11-14-2021

This is an Arduino Project that tracks and displays the number of days until my dad retires.

# Images

<img src="https://user-images.githubusercontent.com/90977640/200122432-5d711601-ff72-49dd-9905-7b01ff2c2cdc.JPG" width=49% height=50%>

<img src="https://user-images.githubusercontent.com/90977640/200122430-a01f5e60-fe14-4f1d-9fc5-928b7bc3b951.JPG" width=49% height=50%>

# Implementation
To display the current number of days left, I used unix time(number of seconds since 1970):
1. Found unix time of when my dad retired(static number), and periodically found current unix time(using wifi)
2. I subtracted the unix time of when my dad retired by the current unix time
3. I converted this number of seconds to days, and then displayed it on the 4-digit 7-segment board

