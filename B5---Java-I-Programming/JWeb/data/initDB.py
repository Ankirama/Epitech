import sqlite3
import sys

class Database:
    '''
    Helper to use sqlite3 and init our database
    '''

    def __init__(self, dbname):
        '''
        It will connect to the database name (or create it) and create (if not exists) our tables
        @param: dbname: database name
        '''
        try:
            self.conn = sqlite3.connect(dbname)
            self.cursor = self.conn.cursor()
        except sqlite3.OperationalError as e:
            print('error in db: ', e)
        else:
            print('connected to %s' % dbname)

    def __del__(self):
        self.cursor.close()
        print('db closed')

    def createTables(self, tablesQueries):
        print('db: create tables ..')
        try:
            for name, query in tablesQueries.iteritems():
                self.cursor.execute(query)
                self.conn.commit()
                print('db: [%s] table created' % name)
        except sqlite3.OperationalError as e:
            print('error during creation table: [%s]' % name, e)
        except BaseException as e:
            print(name)

    def flushTables(self, tables):
        print('db: flush tables...')
        try:
            for name in tables.keys():
                self.cursor.execute("DROP TABLE IF EXISTS %s;" % name)
                self.conn.commit()
                print('db: [%s] table deleted' % name)
        except sqlite3.OperationalError as e:
            print('error during removing table: ', e)

def main():
    '''
    This scrip will allow us to create our database and tables
    '''
    tablesQueries = {}

    tablesQueries['user'] = 'CREATE TABLE IF NOT EXISTS user (' \
                            'id INTEGER PRIMARY KEY AUTOINCREMENT,' \
                            'username TEXT UNIQUE NOT NULL,' \
                            'password TEXT NOT NULL,' \
                            'email TEXT UNIQUE NOT NULL,' \
                            'first_name TEXT DEFAULT "",' \
                            'last_name TEXT DEFAULT "",' \
                            'admin INTEGER NOT NULL DEFAULT 0,' \
                            'active INTEGER DEFAULT 1'\
                            ');'
    tablesQueries['address'] = 'CREATE TABLE IF NOT EXISTS address (' \
                               'id INTEGER PRIMARY KEY AUTOINCREMENT,' \
                               'name TEXT UNIQUE NOT NULL,' \
                               'first_name TEXT NOT NULL,'\
                               'last_name TEXT NOT NULL,'\
                               'address1 TEXT NOT NULL,' \
                               'address2 TEXT,' \
                               'city TEXT NOT NULL,' \
                               'country TEXT NOT NULL,' \
                               'userid INTEGER,' \
                               'FOREIGN KEY(userid) REFERENCES user(id)' \
                               ');'
    tablesQueries['payment'] = 'CREATE TABLE IF NOT EXISTS payment('\
                                'id INTEGER PRIMARY KEY AUTOINCREMENT,'\
                                'name TEXT UNIQUE NOT NULL,'\
                                'card_numbers TEXT UNIQUE NOT NULL,'\
                                'first_name TEXT NOT NULL,'\
                                'last_name TEXT NOT NULL,'\
                                'userid INTEGER,'\
                                'FOREIGN KEY(userid) REFERENCES user(id)'\
                                ');'
    tablesQueries['category'] = 'CREATE TABLE IF NOT EXISTS category('\
                                'id INTEGER PRIMARY KEY AUTOINCREMENT,'\
                                'name TEXT NOT NULL UNIQUE,'\
                                'slug TEXT NOT NULL UNIQUE'\
                                ')'
    tablesQueries['product'] = 'CREATE TABLE IF NOT EXISTS product(' \
                               'id INTEGER PRIMARY KEY AUTOINCREMENT,' \
                               'name TEXT NOT NULL,' \
                               'price REAL NOT NULL,' \
                               'illustration TEXT NOT NULL, '\
                               'description TEXT NOT NULL,' \
                               'active INTEGER NOT NULL DEFAULT 1,'\
                               'categoryid INTEGER,'\
                               'FOREIGN KEY(categoryid) REFERENCES category(id)'\
                               ');'
    tablesQueries['opinion'] = 'CREATE TABLE IF NOT EXISTS opinion (' \
                               'id INTEGER PRIMARY KEY AUTOINCREMENT,' \
                               'note INTEGER NOT NULL DEFAULT 0,' \
                               'comment TEXT NOT NULL,' \
                               'author TEXT NOT NULL,' \
                               'productid INTEGER,'\
                               'FOREIGN KEY(productid) REFERENCES product(id)'\
                               ');'
    tablesQueries['newsletter'] = 'CREATE TABLE IF NOT EXISTS newsletter ('\
                                  'id INTEGER PRIMARY KEY AUTOINCREMENT, '\
                                  'email TEXT UNIQUE NOT NULL'\
                                  ');'
    tablesQueries['news'] = 'CREATE TABLE IF NOT EXISTS news ('\
                            'id INTEGER PRIMARY KEY AUTOINCREMENT,'\
                            'illustration TEXT NOT NULL, '\
                            'date_created DATETIME DEFAULT CURRENT_TIMESTAMP,'\
                            'title TEXT NOT NULL,'\
                            'content TEXT NOT NULL,'\
                            'author TEXT NOT NULL'\
                            ');'
    db = Database('jweb.db')
    db.createTables(tablesQueries)
    print('___')
    #db.cursor.execute('SELECT * FROM user;')
    #print(db.cursor.fetchall())

if __name__ == '__main__':
    main()
