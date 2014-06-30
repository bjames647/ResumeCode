#!/usr/bin/python
import sys
import os
#import pygame
import subprocess as sp
#from pygame.locals import *
import gdata.youtube
import gdata.youtube.service
import httplib
import httplib2
import os
import random
import sys
import time
from Tkinter import Frame, Tk, BOTH, Text, Menu, END, Button, SUNKEN
import tkFileDialog 
import tkColorChooser 
from apiclient.discovery import build
from apiclient.errors import HttpError
from apiclient.http import MediaFileUpload
from oauth2client.file import Storage
from oauth2client.client import flow_from_clientsecrets
from oauth2client.tools import run
from optparse import OptionParser
from pdb import set_trace as debug
from Tkinter import *
import glob
# Explicitly tell the underlying HTTP transport library not to retry, since
# we are handling retry logic ourselves.
httplib2.RETRIES = 1

# Maximum number of times to retry before giving up.
MAX_RETRIES = 10

# Always retry when these exceptions are raised.
RETRIABLE_EXCEPTIONS = (httplib2.HttpLib2Error, IOError, httplib.NotConnected,
  httplib.IncompleteRead, httplib.ImproperConnectionState,
  httplib.CannotSendRequest, httplib.CannotSendHeader,
  httplib.ResponseNotReady, httplib.BadStatusLine)

# Always retry when an apiclient.errors.HttpError with one of these status
# codes is raised.
RETRIABLE_STATUS_CODES = [500, 502, 503, 504]

# CLIENT_SECRETS_FILE, name of a file containing the OAuth 2.0 information for
# this application, including client_id and client_secret. You can acquire an
# ID/secret pair from the API Access tab on the Google APIs Console
#   http://code.google.com/apis/console#access
# For more information about using OAuth2 to access Google APIs, please visit:
#   https://developers.google.com/accounts/docs/OAuth2
# For more information about the client_secrets.json file format, please visit:
#   https://developers.google.com/api-client-library/python/guide/aaa_client_secrets
# Please ensure that you have enabled the YouTube Data API for your project.
CLIENT_SECRETS_FILE = "client_secrets.json"

# A limited OAuth 2 access scope that allows for uploading files, but not other
# types of account access.
YOUTUBE_UPLOAD_SCOPE = "https://www.googleapis.com/auth/youtube.upload"
YOUTUBE_API_SERVICE_NAME = "youtube"
YOUTUBE_API_VERSION = "v3"

# Helpful message to display if the CLIENT_SECRETS_FILE is missing.
MISSING_CLIENT_SECRETS_MESSAGE = """
WARNING: Please configure OAuth 2.0

To make this sample run you will need to populate the client_secrets.json file
found at:

   %s

with information from the APIs Console
https://code.google.com/apis/console#access

For more information about the client_secrets.json file format, please visit:
https://developers.google.com/api-client-library/python/guide/aaa_client_secrets
""" % os.path.abspath(os.path.join(os.path.dirname(__file__), CLIENT_SECRETS_FILE))
options = ''


def main():
	yt_service = gdata.youtube.service.YouTubeService()
	# Turn on HTTPS/SSL access.
	# Note: SSL is not available at this time for uploads.
	yt_service.ssl = True

	yt_service.developer_key = 'AIzaSyBqhJsUqaRm6_gxXjz2s2jay00DND000OA'
	yt_service.client_id = '566256484434.apps.googleusercontent.com'

	# A complete client login request
	yt_service.email = strUsername.get()
	yt_service.password = strPasswordEntry.get()
	yt_service.source = 'Youtube Uploader'
	yt_service.developer_key = 'AIzaSyBqhJsUqaRm6_gxXjz2s2jay00DND000OA'
	yt_service.client_id = '566256484434.apps.googleusercontent.com'
	yt_service.ProgrammaticLogin()
	

	if strUploadFile1.get() != "":
		if __name__ == '__main__':
			parser = OptionParser()
			parser.add_option('--file', dest='file', help="Video file to upload")
			parser.add_option("--title", dest="title", help="Video title",
			default="Test Title")
			parser.add_option("--description", dest="description",
				help="Video description",
				default="Test Description")
			parser.add_option("--category", dest="category",
				help="Numeric video category. " +
					"See https://developers.google.com/youtube/v3/docs/videoCategories/list",
				default="22")
			parser.add_option("--keywords", dest="keywords",
				help="Video keywords, comma separated", default="")
			parser.add_option("--privacyStatus", dest="privacyStatus",
				help="Video privacy status: public, private or unlisted",
				default="public")
			(options, args) = parser.parse_args()
			initialize_upload(options, strUploadFile1.get(), strUploadTitle1.get())

	if strUploadFile2.get() != "":
		if __name__ == '__main__':
			parser = OptionParser()
			parser.add_option('--file', dest='file', help="Video file to upload")
			parser.add_option("--title", dest="title", help="Video title",
			default="Test Title")
			parser.add_option("--description", dest="description",
				help="Video description",
				default="Test Description")
			parser.add_option("--category", dest="category",
				help="Numeric video category. " +
					"See https://developers.google.com/youtube/v3/docs/videoCategories/list",
				default="22")
			parser.add_option("--keywords", dest="keywords",
				help="Video keywords, comma separated", default="")
			parser.add_option("--privacyStatus", dest="privacyStatus",
				help="Video privacy status: public, private or unlisted",
				default="public")
			(options, args) = parser.parse_args()
			initialize_upload(options, strUploadFile2.get(), strUploadTitle2.get())	

	if strUploadFile3.get() != "":
		if __name__ == '__main__':
			parser = OptionParser()
			parser.add_option('--file', dest='file', help="Video file to upload")
			parser.add_option("--title", dest="title", help="Video title",
			default="Test Title")
			parser.add_option("--description", dest="description",
				help="Video description",
				default="Test Description")
			parser.add_option("--category", dest="category",
				help="Numeric video category. " +
					"See https://developers.google.com/youtube/v3/docs/videoCategories/list",
				default="22")
			parser.add_option("--keywords", dest="keywords",
				help="Video keywords, comma separated", default="")
			parser.add_option("--privacyStatus", dest="privacyStatus",
				help="Video privacy status: public, private or unlisted",
				default="public")
			(options, args) = parser.parse_args()
			initialize_upload(options, strUploadFile3.get(), strUploadTitle3.get())	
	
	if strUploadFile4.get() != "":
		if __name__ == '__main__':
			parser = OptionParser()
			parser.add_option('--file', dest='file', help="Video file to upload")
			parser.add_option("--title", dest="title", help="Video title",
			default="Test Title")
			parser.add_option("--description", dest="description",
				help="Video description",
				default="Test Description")
			parser.add_option("--category", dest="category",
				help="Numeric video category. " +
					"See https://developers.google.com/youtube/v3/docs/videoCategories/list",
				default="22")
			parser.add_option("--keywords", dest="keywords",
				help="Video keywords, comma separated", default="")
			parser.add_option("--privacyStatus", dest="privacyStatus",
				help="Video privacy status: public, private or unlisted",
				default="public")
			(options, args) = parser.parse_args()
			initialize_upload(options, strUploadFile4.get(), strUploadTitle4.get())

			
	if strUploadFile5.get() != "":
		if __name__ == '__main__':
			parser = OptionParser()
			parser.add_option('--file', dest='file', help="Video file to upload")
			parser.add_option("--title", dest="title", help="Video title",
			default="Test Title")
			parser.add_option("--description", dest="description",
				help="Video description",
				default="Test Description")
			parser.add_option("--category", dest="category",
				help="Numeric video category. " +
					"See https://developers.google.com/youtube/v3/docs/videoCategories/list",
				default="22")
			parser.add_option("--keywords", dest="keywords",
				help="Video keywords, comma separated", default="")
			parser.add_option("--privacyStatus", dest="privacyStatus",
				help="Video privacy status: public, private or unlisted",
				default="public")
			(options, args) = parser.parse_args()
			initialize_upload(options, strUploadFile5.get(), strUploadTitle5.get())
		
def get_authenticated_service():
  flow = flow_from_clientsecrets(CLIENT_SECRETS_FILE, scope=YOUTUBE_UPLOAD_SCOPE,
    message=MISSING_CLIENT_SECRETS_MESSAGE)

  storage = Storage("%s-oauth2.json" % sys.argv[0])
  credentials = storage.get()

  if credentials is None or credentials.invalid:
    credentials = run(flow, storage)

  return build(YOUTUBE_API_SERVICE_NAME, YOUTUBE_API_VERSION,
    http=credentials.authorize(httplib2.Http()))

def initialize_upload(options, strFile, strTitle):
  youtube = get_authenticated_service()
  options.file = strFile
  options.title = strTitle
  options.description = strUploadDescription.get()  
  tags = None
  if options.keywords:
    tags = options.keywords.split(",")
  print options.file
  insert_request = youtube.videos().insert(
    part="snippet,status",
    body=dict(
      snippet=dict(
        title=options.title,
        description=options.description,
        tags=tags,
        categoryId=options.category
      ),
      status=dict(
        privacyStatus=options.privacyStatus
      )
    ),
    # chunksize=-1 means that the entire file will be uploaded in a single
    # HTTP request. (If the upload fails, it will still be retried where it
    # left off.) This is usually a best practice, but if you're using Python
    # older than 2.6 or if you're running on App Engine, you should set the
    # chunksize to something like 1024 * 1024 (1 megabyte).
	
    media_body=MediaFileUpload(options.file, chunksize=-1, resumable=True)
  )

  resumable_upload(insert_request)


def resumable_upload(insert_request):
  response = None
  error = None
  retry = 0
  while response is None:
    try:
      print "Uploading file..."
      status, response = insert_request.next_chunk()
      if 'id' in response:
        print "'%s' (video id: %s) was successfully uploaded." % (
          options.title, response['id'])
      else:
        exit("The upload failed with an unexpected response: %s" % response)
    except HttpError, e:
      if e.resp.status in RETRIABLE_STATUS_CODES:
        error = "A retriable HTTP error %d occurred:\n%s" % (e.resp.status,
                                                             e.content)
      else:
        raise
    except RETRIABLE_EXCEPTIONS, e:
      error = "A retriable error occurred: %s" % e

    if error is not None:
      print error
      retry += 1
      if retry > MAX_RETRIES:
        exit("No longer attempting to retry.")

      max_sleep = 2 ** retry
      sleep_seconds = random.random() * max_sleep
      print "Sleeping %f seconds and then retrying..." % sleep_seconds
      time.sleep(sleep_seconds)
	  		
		
		
app = Tk()
app.title("Bulk YouTube Uploader")
app.geometry('370x200')

usernameLabel = Label(app, text="Username:")
usernameLabel.grid(row=0, sticky=(E))
strUsername = StringVar()
usernameEntry = Entry(app, textvariable=strUsername)
usernameEntry.grid(row=0, column=1, sticky=(E))

passwordLabel = Label(app, text="Password:")
passwordLabel.grid(row=1, sticky=(E))
strPasswordEntry = StringVar()
passwordEntry = Entry(app, textvariable=strPasswordEntry, show="*")
passwordEntry.grid(row=1, column=1, sticky=(E))

#UPLOAD FILES
uploadFileLabel = Label(app, text="File:")
uploadFileLabel.grid(row=3, sticky=(E))
strUploadFile1 = StringVar()
uploadFile = Entry(app, textvariable=strUploadFile1)
uploadFile.grid(row=3, column=1, sticky=(E))		

uploadFileLabel = Label(app, text="File:")
uploadFileLabel.grid(row=4, sticky=(E))
strUploadFile2 = StringVar()
uploadFile = Entry(app, textvariable=strUploadFile2)
uploadFile.grid(row=4, column=1, sticky=(E))

uploadFileLabel = Label(app, text="File:")
uploadFileLabel.grid(row=5, sticky=(E))
strUploadFile3 = StringVar()
uploadFile = Entry(app, textvariable=strUploadFile3)
uploadFile.grid(row=5, column=1, sticky=(E))

uploadFileLabel = Label(app, text="File:")
uploadFileLabel.grid(row=6, sticky=(E))
strUploadFile4 = StringVar()
uploadFile = Entry(app, textvariable=strUploadFile4)
uploadFile.grid(row=6, column=1, sticky=(E))

uploadFileLabel = Label(app, text="File:")
uploadFileLabel.grid(row=7, sticky=(E))
strUploadFile5 = StringVar()
uploadFile = Entry(app, textvariable=strUploadFile5)
uploadFile.grid(row=7, column=1, sticky=(E))

#UPLOAD TITLES
uploadTitleLabel = Label(app, text="Title:")
uploadTitleLabel.grid(row=3, column=2, sticky=(E))
strUploadTitle1 = StringVar()
uploadTitle1 = Entry(app, textvariable=strUploadTitle1)
uploadTitle1.grid(row=3, column=3, sticky=(E))

uploadTitleLabel = Label(app, text="Title:")
uploadTitleLabel.grid(row=4, column=2, sticky=(E))
strUploadTitle2 = StringVar()
uploadTitle1 = Entry(app, textvariable=strUploadTitle2)
uploadTitle1.grid(row=4, column=3, sticky=(E))

uploadTitleLabel = Label(app, text="Title:")
uploadTitleLabel.grid(row=5, column=2, sticky=(E))
strUploadTitle3 = StringVar()
uploadTitle1 = Entry(app, textvariable=strUploadTitle3)
uploadTitle1.grid(row=5, column=3, sticky=(E))

uploadTitleLabel = Label(app, text="Title:")
uploadTitleLabel.grid(row=6, column=2, sticky=(E))
strUploadTitle4 = StringVar()
uploadTitle1 = Entry(app, textvariable=strUploadTitle4)
uploadTitle1.grid(row=6, column=3, sticky=(E))

uploadTitleLabel = Label(app, text="Title:")
uploadTitleLabel.grid(row=7, column=2, sticky=(E))
strUploadTitle5 = StringVar()
uploadTitle1 = Entry(app, textvariable=strUploadTitle5)
uploadTitle1.grid(row=7, column=3, sticky=(E))
'''
uploadDescriptionLabel = Label(app, text="Description:")
uploadDescriptionLabel.grid(row=101, sticky=(E))
strUploadDescription = StringVar()
uploadDescription = Entry(app, textvariable=strUploadDescription)
uploadDescription.grid(row=101, column=1, sticky=(E))
'''
uploadButton = Button(app, text="Upload", width = 10, command=main)
uploadButton.grid(row=102, column=1, sticky=(N,S,E,W))

app.mainloop()