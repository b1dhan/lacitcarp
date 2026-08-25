CREATE DATABASE joindb;
USE joindb;

CREATE TABLE Department (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50) NOT NULL,
    HOD VARCHAR(50) NOT NULL
);

CREATE TABLE Employee (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50) NOT NULL,
    position VARCHAR(50) NOT NULL,
    salary INT NOT NULL,
    dept_id INT
);

INSERT INTO Department (dept_id, dept_name, HOD) VALUES
(1, 'Sales', 'Bob'),
(2, 'Marketing', 'Alice'),
(3, 'Finance', 'Gita'),
(4, 'Operations', 'Shyam');

INSERT INTO Employee (emp_id, emp_name, position, salary, dept_id) VALUES
(1, 'Anish', 'Manager', 25000, 1),
(2, 'Ram', 'Secretary', 20000, 2),
(3, 'Sam', 'Analyst', 15000, 5),
(4, 'Hari', 'Manager', 25000, 3);

SELECT * FROM Department INNER JOIN Employee ON Department.dept_id = Employee.dept_id;

SELECT * FROM Department LEFT JOIN Employee ON Department.dept_id = Employee.dept_id;

SELECT * FROM Department RIGHT JOIN Employee ON Department.dept_id = Employee.dept_id;

SELECT * FROM Department LEFT JOIN Employee ON Department.dept_id = Employee.dept_id
UNION
SELECT * FROM Department RIGHT JOIN Employee ON Department.dept_id = Employee.dept_id;

SELECT * FROM Department NATURAL JOIN Employee;

SELECT * FROM Employee CROSS JOIN Department;

SELECT e.emp_name,d.dept_name 
FROM Employee e INNER JOIN Department d ON e.dept_id=d.dept_id;

SELECT e.emp_name,e.position,e.salary 
FROM Employee e INNER JOIN Department d ON e.dept_id=d.dept_id
WHERE dept_name='Finance';

SELECT e.emp_name
FROM Employee e INNER JOIN Department d ON e.dept_id=d.dept_id
WHERE dept_name='Sales';

SELECT e.*,d.*
FROM Employee e INNER JOIN Department d ON e.dept_id=d.dept_id
WHERE dept_name='Marketing';

SELECT d.HOD
FROM Employee e INNER JOIN Department d ON e.dept_id=d.dept_id
WHERE emp_name='Hari';

-- -------------------------------------------------------------

CREATE TABLE emp_computerdept (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50) NOT NULL,
    address VARCHAR(50) NOT NULL
);

CREATE TABLE emp_csitdept (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50) NOT NULL,
    address VARCHAR(50) NOT NULL
);

INSERT INTO emp_computerdept (emp_id, emp_name, address) VALUES
(1, 'Aarush', 'Biratnagar'),
(2, 'Aaryan', 'Dharan'),
(3, 'Aashik', 'Kathmandu'),
(4, 'Aditi', 'Surkhet'),
(5, 'Amit', 'Dhangadi');

INSERT INTO emp_csitdept (emp_id, emp_name, address) VALUES
(1, 'Anjali', 'Butwal'),
(2, 'Ansila', 'Bajhang'),
(3, 'Benjamin', 'Kathmandu'),
(4, 'Bhairab', 'Surkhet'),
(5, 'Arati', 'Dhangadi');

SELECT * FROM emp_computerdept
UNION
SELECT * FROM emp_csitdept;

SELECT emp_id, emp_name, address FROM emp_computerdept
UNION ALL
SELECT emp_id, emp_name, address FROM emp_csitdept;

SELECT DISTINCT c.address FROM emp_computerdept c
INNER JOIN emp_csitdept s ON c.address = s.address;

SELECT address FROM emp_computerdept WHERE address NOT IN (
	SELECT address FROM emp_csitdept  );

SELECT emp_name FROM emp_computerdept
UNION
SELECT emp_name FROM emp_csitdept;

SELECT c.emp_name FROM emp_computerdept c
INNER JOIN emp_csitdept s ON c.emp_id = s.emp_id;

SELECT emp_name FROM emp_csitdept WHERE emp_name NOT IN (
    SELECT emp_name FROM emp_computerdept );

SELECT DISTINCT c.address FROM emp_computerdept c
INNER JOIN emp_csitdept s ON c.address = s.address;
