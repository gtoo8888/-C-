
```sql
CREATE TABLE "student" (
  "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
  "name" TEXT,
  "age" integer,
  "grade" integer,
  "class" integer,
  "studentid" integer,
  "phone" TEXT,
);
```

```sql
CREATE TABLE "username" (
  "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
  "username" TEXT,
  "password" TEXT,
  "auth" TEXT
);

```

select count(id) from student;


select * from student order by id limit 2 offset 1;

INSERT INTO "student" VALUES (NULL, '张三', 12, 3, 2, 1, 15940224444, 'asdzhang');

delete from student where id = 1;

delete from student;

update student set name = 'asd' where id=25;

select * from username

update username set auth='user';

INSERT INTO "username" VALUES ('admin', 111, 'admin');

delete from username where username='admin';


https://yujiang.blog.csdn.net/article/details/122516188
