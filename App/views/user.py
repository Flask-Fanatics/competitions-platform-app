from flask import Blueprint, render_template, jsonify, request, send_from_directory, flash, redirect, url_for
from flask_jwt_extended import jwt_required, current_user as jwt_current_user
from flask_login import current_user, login_required

from.index import index_views

from App.controllers import (
    create_user,
    jwt_authenticate, 
    get_all_users,
    get_all_users_json,
    jwt_required
)

user_views = Blueprint('user_views', __name__, template_folder='../templates')

@user_views.route('/users', methods=['GET'])
def get_user_page():
    users = get_all_users()
    return render_template('users.html', users=users)

@user_views.route('/api/users', methods=['GET'])
def get_users_action():
    users = get_all_users_json()
    return jsonify(users)

@user_views.route('/api/users', methods=['POST'])
def create_user_endpoint():
    data = request.json
    create_user(data['username'], data['password'])
    return jsonify({'message': f"user {data['username']} created"})

@user_views.route('/users', methods=['POST'])
def create_user_action():
    data = request.form
    flash(f"User {data['username']} created!")
    create_user(data['username'], data['password'])
    return redirect(url_for('user_views.get_user_page'))

@user_views.route('/static/users', methods=['GET'])
def static_user_page():
  return send_from_directory('static', 'static-user.html')

# @user_views.route('/signup', methods=['GET'])
# def signup_page():
#   return render_template('signup.html')



# @user_views.route('/signup', methods=['POST'])
# def signup_action():
#   data = request.form  # get data from form submission
#   newuser = participant(username=data['username'], email=data['email'], password=data['password'])  # create user object
#   try:
#     db.session.add(newuser)
#     db.session.commit()  # save user
#     login_user(newuser)  # login the user
#     flash('Account Created!')  # send message
#     return redirect(url_for('login_action'))  # redirect to homepage
#   except Exception:  # attempted to insert a duplicate user
#     db.session.rollback()
#     flash("username or email already exists")  # error message
#   return redirect(url_for('login_action'))

# @user_views.route('/', methods=['GET'])
# @user_views.route('/login', methods=['GET'])
# def login_page():
#   return render_template('login.html')

