from werkzeug.security import check_password_hash, generate_password_hash
from flask_login import UserMixin
from App.database import db
# from App.models import Result


class Competition(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100), nullable=False)
    start_date = db.Column(db.DateTime, nullable=False)
    end_date = db.Column(db.DateTime, nullable=False)
    # admin_id = db.Column(db.Integer, db.ForeignKey('admin.id'), nullable=False)
    result = db.Column(db.Integer, nullable=False)
    # results = db.relationship('Result', backref='competition', lazy=True)