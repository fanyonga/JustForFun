#coding:utf-8

import requests


url="http://www.baidu.com"
report=requests.get(url)
print report.text
