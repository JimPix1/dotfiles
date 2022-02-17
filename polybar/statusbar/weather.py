#!/bin/python
# -*- coding: utf-8 -*-

# Procedure
# Surf to https://openweathermap.org/city
# Fill in your CITY
# e.g. Antwerp Belgium
# Check url
# https://openweathermap.org/city/2803138
# you will the city code at the end
# create an account on this website
# create an api key (free)

import requests

CITY = "2966485"
API_KEY = "756edce7e9d4c385ef9499a53492678c"
UNITS = "Metric"
UNIT_KEY = "C"
#UNIT_KEY = "F"
LANG = "en"
try:
    REQ = requests.get("http://api.openweathermap.org/data/2.5/weather?id={}&lang={}&appid={}&units={}".format(CITY, LANG,  API_KEY, UNITS))

    # HTTP CODE = OK
    if REQ.status_code == 200:
        CURRENT = REQ.json()["weather"][0]["description"].capitalize()
        TEMP = int(float(REQ.json()["main"]["temp"]))
        print("{}, {}°{}".format(CURRENT, TEMP, UNIT_KEY))
except:
    pass
