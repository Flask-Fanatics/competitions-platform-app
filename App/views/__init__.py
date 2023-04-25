# blue prints are imported 
# explicitly instead of using *
from .user import user_views
from .index import index_views
from .auth import auth_views
from .part import part_views
from .uploads import upload_views
from .results import result_views


views = [user_views, index_views, auth_views, part_views, upload_views, result_views] 
# blueprints must be added to this list