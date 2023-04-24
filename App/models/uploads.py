import uuid
from .user import User
# from App.models import User
# from .participant import Particpant
from werkzeug.security import check_password_hash, generate_password_hash
from flask_login import UserMixin
from App.database import db
from uploads import store_file, remove_file


class Upload(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    filename = db.Column(db.String, nullable=False)
    # data = db.Column(db.LargeBinary)

    # def __init__(self, user_id, filename):
    def __init__(self, file):
      #  self.user_id = user_id
       self.filename = store_file(file)

    def remove_file(self):
      remove_file(self.filename)

    def get_url(self):
      return f'/uploads/{self.filename}'