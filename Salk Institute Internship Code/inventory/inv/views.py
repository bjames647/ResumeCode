# Create your views here.

from django.template.context import RequestContext
from django.shortcuts import get_object_or_404, render_to_response
from pdb import set_trace as debug
from django.contrib.auth.decorators import login_required
from django.http import HttpRequest, HttpResponse
from django.shortcuts import redirect
from django.contrib.auth.decorators import login_required
from django.core.urlresolvers import reverse_lazy, reverse
from django.forms import ModelForm
from django.utils.safestring import mark_safe
from django.views.decorators.csrf import csrf_exempt
import json
import pickle
import base64
import sys
import os
from django.views.decorators.csrf import csrf_exempt
from django.utils.timezone import now
from inv.models import *
import socket
hostname = socket.getfqdn()
from django.conf import settings

@csrf_exempt
def workstations(request):
	hostname = request.POST.get('hostname', None)
	if hostname:
		wk, new = Workstation.objects.get_or_create(name=hostname)
		wk.version = request.POST.get('version', -1)
		wk.versionstr = request.POST.get("versionstr","-1")
		wk.applications.clear()
		wk.save()
	applist = json.loads(request.POST.get('applist', None))
	for app in applist:
		thisapp, new = Application.objects.get_or_create(**app)
		wk.applications.add(thisapp)
		wk.save()
	
	workstations = Workstation.objects.all()
	return render_to_response('workstations.html', {"workstations":workstations}, \
		context_instance=RequestContext(request))