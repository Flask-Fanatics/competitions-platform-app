from flask import Blueprint, render_template, jsonify, request, send_from_directory, flash, redirect, url_for
from flask_jwt_extended import jwt_required, current_user as jwt_current_user
from flask_login import current_user, login_required
from flask_cors import CORS
import os, functools
from functools import wraps
from flask import Flask, flash
from werkzeug.utils import secure_filename
from App.models import Upload
from App.models import db


app = Flask(__name__)
# app.config["UPLOADED_PHOTOS_DEST"] = "uploads"
# app.config['PREFERRED_URL_SCHEME'] = 'https'
# photos = UploadSet("files", FILES)
# configure_uploads(app, files)

from.index import index_views

from App.controllers import (
    create_user,
    jwt_authenticate, 
    get_all_users,
    get_all_users_json,
    jwt_required
)

upload_views = Blueprint('upload_views', __name__, template_folder='../templates')

UPLOAD_FOLDER = '/path/to/the/uploads'
ALLOWED_EXTENSIONS = {'py', 'php', 'sh', 'jpg', 'java', 'cpp'}
def allowed_file(filename):
  if '.' in filename:
    ext = filename.rsplit('.', 1)[1].lower()
    return ext in ALLOWED_EXTENSIONS
  return False


# @upload_views.route('/uploads', methods=['GET'])
# def uploader_page():
#   return render_template('uploader.html')

@upload_views.route('/uploads/<path:name>', methods=["GET"])
def download_file(name):
  return send_from_directory('uploads', name)

@upload_views.route('/uploads', methods=['GET'])
def uploader():
  uploads = Upload.query.all()
  return render_template('uploader.html', uploads=uploads)

@upload_views.route('/upload', methods=['POST'])
def upload_action():
  if 'file' not in request.files:
    flash('No file in request')
    return redirect('/uploads')
  file = request.files['file']
  if not allowed_file(file.filename):
    flash(f'Invalid file format {file.filename} uploaded')
    return redirect('/uploads')
  newupload = Upload(file)
  db.session.add(newupload)
  db.session.commit()
  flash('file uploaded!')
  return redirect('/uploads')

@upload_views.route('/deleteUpload/<int:id>', methods=['GET'])
def delete_file(id):
  upload = Upload.query.get(id)
  if upload:
    upload.remove_file()
    db.session.delete(upload)
    db.session.commit()
    flash('Upload Deleted')
  return redirect('/uploads')