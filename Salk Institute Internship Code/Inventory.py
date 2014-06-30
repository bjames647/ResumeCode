import sys, os
from pdb import set_trace as debug
import subprocess as sp
import platform
import urllib, urllib2
import json

result = sp.Popen(['wmic','product','get','name,version'], stdout=sp.PIPE, stderr=sp.PIPE).communicate()

wmic = result[0]
wmic = wmic.split("\n")

splitcol = wmic[0].index("Version")
applist = []
for line in wmic[1:]:
	appversion =  line[splitcol:].strip()
	appname = line[:splitcol].strip()
	app = {"name": appname, "version":appversion}
	applist.append(app)


data = {
	"applist":json.dumps(applist),
	"hostname":platform.uname()[1],
	"versionstr":platform.uname()[3],
}

vList = data["versionstr"].split(".")
vStr = vList[0] + "." + "".join(vList[1:])
version = float(vStr)
data['version'] = version


result = urllib2.urlopen("http://localhost:8000", urllib.urlencode(data)).read()
print result
