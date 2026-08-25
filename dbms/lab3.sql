CREATE DATABASE Bernhardt;

USE Bernhardt;

CREATE TABLE EMPLOYEE (
    EMPNO INT(4),
    ENAME VARCHAR(20),
    DESIGNATION VARCHAR(25),
    HIREDATE DATE,
    SALARY INT(10),
    COMM DECIMAL(10,2),
    DEPTNO INT(4)
);

DESCRIBE EMPLOYEE;

ALTER TABLE EMPLOYEE
DROP COLUMN COMM;

ALTER TABLE EMPLOYEE
RENAME COLUMN DEPTNO TO DPNO;

ALTER TABLE EMPLOYEE
ADD PHONE BIGINT;

ALTER TABLE EMPLOYEE
MODIFY EMPNO VARCHAR(5);

DROP TABLE EMPLOYEE;

DROP DATABASE Bernhardt;

CREATE DATABASE Bernhardt;

USE Bernhardt;

CREATE TABLE EMPLOYEE (
    EMPNO INT(4),
    ENAME VARCHAR(20),
    DESIGNATION VARCHAR(25),
    HIREDATE DATE,
    SALARY INT(10),
    COMM DECIMAL(10,2),
    DEPTNO INT(4)
);

INSERT INTO EMPLOYEE (EMPNO, ENAME, DESIGNATION, HIREDATE, SALARY, COMM, DEPTNO)
VALUES
(1011, 'Ram', 'Manager', '1995-01-01', 20000, 800, 100),
(1021, 'Hari', 'Accountant', '1999-04-04', 15000, 650, 200),
(1456, 'Shyam', 'Clerk', '1995-07-03', 12000, 500, 300),
(1045, 'Sita', 'Analyst', '1998-10-06', 18000, 700, 400),
(1099, 'Ramesh', 'Clerk', '1996-01-01', 10000, 400, 300),
(1060, 'Hari', 'Clerk', '1997-10-25', 10000, 400, 300);

SELECT * FROM EMPLOYEE;

SELECT ENAME, DESIGNATION, SALARY
FROM EMPLOYEE;

SELECT ENAME
FROM EMPLOYEE
WHERE DESIGNATION = 'Clerk';

SELECT *
FROM EMPLOYEE
WHERE DESIGNATION = 'Clerk'
AND DEPTNO = 300;

SELECT ENAME, EMPNO, DESIGNATION
FROM EMPLOYEE
WHERE DESIGNATION IN ('Manager', 'Analyst');

SELECT *
FROM EMPLOYEE
WHERE DESIGNATION NOT IN ('Director', 'Receptionist');

SELECT *
FROM EMPLOYEE
WHERE DESIGNATION IN ('Director', 'Receptionist');

SELECT ENAME, SALARY
FROM EMPLOYEE
WHERE SALARY BETWEEN 12000 AND 20000;

SELECT ENAME, SALARY
FROM EMPLOYEE
WHERE SALARY < 10000
OR SALARY > 15000;

SELECT DISTINCT DESIGNATION
FROM EMPLOYEE;

SELECT ENAME
FROM EMPLOYEE
WHERE ENAME LIKE 'R%';

SELECT EMPNO, ENAME
FROM EMPLOYEE
WHERE ENAME LIKE '%m';

SELECT ENAME
FROM EMPLOYEE
WHERE ENAME LIKE 'H%i';

SELECT ENAME, EMPNO
FROM EMPLOYEE
WHERE ENAME LIKE 'R__';

SELECT ENAME
FROM EMPLOYEE
ORDER BY ENAME ASC;

SELECT ENAME
FROM EMPLOYEE
ORDER BY ENAME DESC;

SELECT ENAME, SALARY * 1.20 AS INCREASED_SALARY
FROM EMPLOYEE;

SELECT ENAME, COMM * 1.20 AS INCREASED_COMM
FROM EMPLOYEE;

SELECT ENAME, (SALARY + COMM) AS TOTAL_SALARY
FROM EMPLOYEE;

SELECT *
FROM EMPLOYEE
WHERE DESIGNATION = 'Manager'
OR SALARY > 12000;

SELECT SUM(SALARY) AS TOTAL_SALARY
FROM EMPLOYEE;

SELECT COUNT(*) AS TOTAL_RECORDS
FROM EMPLOYEE;

CREATE TABLE student (
Std_id INT NOT NULL,
DeptName VARCHAR(20),
Name VARCHAR(50),
Age int,
PhoneNo bigint
);

CREATE DATABASE customers_db;

create table customers(
	customer_id int primary key,
    name varchar(20) not null,
    email varchar(30),
    age int,
    address varchar(30)
);

alter table customers
add unique(email);

alter table customers
add constraint age_check check(age>18);

alter table customers 
alter address set default "bhaktapur";

insert into customers values(1,'ram','ram@gmail.com',22,'kathmandu');
insert into customers values(2,'sita','sita@gmail.com',25,'pokhara');

insert into customers values (3,'gita','gita@gmail.com',26,'butwal');
select * from customers;

insert into customers values (4,'hari','hari@gmail.com',27,'lalitpur');
insert into customers values (11,'ganesh','ganesh@gmail.com',15,'dolkha');

insert into customers values (16,'ramesh','ram@gmail.com',24,'chitwan');

insert into customers(customer_id,name,email,age) values(5,'gopal','gopal@gmail.com',20);
select * from customers;

create table orders(
	order_id int primary key,
    product_name varchar(20),
    price int,
    customer_id int,
    foreign key(customer_id) references customers(customer_id) 
);

update customers set name='gita' where customer_id=3;

insert into orders values(1,'iron',1200,1);
insert into orders values(2,'guitar',4500,2);
insert into orders values (3,'phone',57000,1);
insert into orders values(4,'printer',88000,3);
insert into orders values(5,'drone',125000,2);
insert into orders values(6,'smartwatch',7500,4);
insert into orders values(7,'oven',14500,5);

insert into orders values(8,'Laptop',158000,6);

select * from customers;
select * from orders;