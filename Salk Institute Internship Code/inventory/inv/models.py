from django.db import models

# Create your models here.
class Application(models.Model):
	name = models.CharField(max_length=60)
	version = models.CharField(max_length=20, default="-1")
	
	def __unicode__(self):
		return("{0}: {1}".format(self.name, self.version))
	
class Workstation(models.Model):
	name = models.CharField(max_length=20)
	platform = models.CharField(max_length=20, default="")
	versionstr = models.CharField(max_length=20, default="")
	version = models.FloatField(default = -1)
	ipaddress = models.CharField(max_length=20, default="", blank=True)
	macaddress = models.CharField(max_length=20, default="", blank=True)
	applications = models.ManyToManyField(Application, related_name="workstations", null=True, blank=True)

	
	def __unicode__(self):
		return("{0}: {1}: {2}".format(self.name, self.platform, self.ipaddress))
	