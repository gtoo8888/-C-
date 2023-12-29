
```sql
CREATE TABLE "student2" (
  "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
  "name" TEXT,
  "sex" TEXT CHECK(sex IN ('男', '女')),
  "age" integer,
  "class" integer,
  "score" integer,
  "studentid" integer,
  "birthday" DATE,
  "phone" TEXT
);


CREATE INDEX idx_student3_id ON student3 (id);
```

```sql
CREATE TABLE "username" (
  "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
  "username" TEXT,
  "password" TEXT,
  "auth" TEXT CHECK(auth IN ('admin', 'teacher', 'student')),
  "rememberpassword" integer
);

CREATE INDEX idx_username_id ON username (id);
```

select count(id) from student;


select * from student order by id limit 2 offset 1;

INSERT INTO "student" VALUES (NULL, '张三', 12, 3, 2, 1, 15940224444, 'asdzhang');

delete from student where id = 1;

delete from student;

update student set name = 'asd' where id=25;

# 用户组表
```sql
CREATE TABLE "username" (
  "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
  "username" TEXT,
  "password" TEXT,
  "auth" TEXT CHECK(auth IN ('admin', 'teacher', 'student')),
  "rememberpassword" integer
);

CREATE INDEX idx_username_id ON username (id);

select * from username

update username set auth='user';

INSERT INTO "username" VALUES (NULL,'stu1', 111, 'student', 0);

delete from username where id=1;
```









https://yujiang.blog.csdn.net/article/details/122516188
