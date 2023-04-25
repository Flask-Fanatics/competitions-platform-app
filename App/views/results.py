from flask import Blueprint, render_template, jsonify, request, send_from_directory, flash, redirect, url_for
from flask_jwt_extended import jwt_required, current_user as jwt_current_user
from flask_login import current_user, login_required
from flask_cors import CORS
import os, functools
from functools import wraps
from flask import Flask, flash
from App.models import Competition
from App.models import db

app = Flask(__name__)

from.index import index_views

from App.controllers import (
    create_user,
    jwt_authenticate, 
    get_all_users,
    get_all_users_json,
    jwt_required
)

result_views = Blueprint('result_views', __name__, template_folder='../templates')

# @result_views.route('/results/<int:competition_id>', methods=["GET"])
# @jwt_required()
# def results(competition_id):
#     competition = Competition.query.get(competition_id)
#     # results = Result.query.filter_by(competition_id=competition_id).all()
#     return render_template('results.html', competition=competition)

@result_views.route('/results', methods=["GET"])
# @jwt_required()
def results():
    # competition = Competition.query.get(competition_id)
    # results = Result.query.filter_by(competition_id=competition_id).all()
    return render_template('results.html')