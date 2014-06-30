__version__ = "1.2"

GOOGLE_AUTH_URI = 'https://accounts.google.com/o/oauth2/auth'
GOOGLE_REVOKE_URI = 'https://accounts.google.com/o/oauth2/revoke'
GOOGLE_TOKEN_URI = 'https://accounts.google.com/o/oauth2/token'

import logging


class NullHandler(logging.Handler):
	def handle(self, record):
		pass
		
	def emit(self, record):
		pass
	
	def createLock(self):
		self.lock = None 
		
logger = logging.getLogger(__name__)
logger.addHandler(NullHandler())