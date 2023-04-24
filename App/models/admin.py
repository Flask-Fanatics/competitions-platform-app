from .user import User
from App.database import db

class Admin(User):
    __tablename__ = 'admin'
    # id = db.Column(db.Integer, db.ForeignKey('user.id'), primary_key=True)
    # competitions = db.relationship('Competition', secondary='participant_competition', backref='participants', lazy=True)

    def __init__(self, username, password):
        self.username = username
        self.set_password(password)
        self.user_type = "participant"

    def __repr__(self):
        return f'<Admin {self.id} {self.username}>'

    def toJSON(self):
        return{
            'id': self.id,
            'username': self.username,
            'role': 'admin',
            'status': self.status
        }