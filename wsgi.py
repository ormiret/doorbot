#!/usr/bin/python

import sys, logging
sys.path.insert(0, '/home/ormiret/webstuff/')
logging.basicConfig(stream=sys.stderr)
from app import app as application

