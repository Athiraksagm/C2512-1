CREATE TABLE departments
(
    id NUMBER GENERATED BY DEFAULT AS IDENTITY START WITH 10 INCREMENT BY 10 PRIMARY KEY,
    name VARCHAR2(125) NOT NULL
);

INSERT INTO departments (id, name) 
VALUES (10,	'Alpha');
INSERT INTO departments (id, name) 
VALUES (20,	'Beta');
INSERT INTO departments (id, name)
VALUES (30,	'Gama');

commit;

DESC departments;

SELECT * FROM departments;

SET LINESIZE 500;
SET TRIMSPOOL ON;
column name format a20;


CREATE TABLE countries
(
    id NUMBER GENERATED BY DEFAULT AS IDENTITY START WITH 11 INCREMENT BY 10 PRIMARY KEY,
    name VARCHAR2(125) NOT NULL,
    ruler VARCHAR2(255) NOT NULL
);
DESC countries;

INSERT INTO countries(id, name, ruler)
VALUES (21,	'USA',	'Trump');
INSERT INTO countries(id, name, ruler)
VALUES (11,	'India',	'Modi');
INSERT INTO countries(id, name, ruler)
VALUES (41,	'Germany',	'Dravid');

commit; 

SET LINESIZE 500;
SET TRIMSPOOL ON;
column name format a20;
column ruler format a20;

SELECT * FROM countries;

CREATE TABLE cities
(
    id NUMBER GENERATED BY DEFAULT AS IDENTITY START WITH 101 INCREMENT BY 1 PRIMARY KEY,
    name VARCHAR2(125) NOT NULL,
    admin VARCHAR2(255) NOT NULL,
    country_id NUMBER NOT NULL
);

DESC cities;

INSERT INTO cities(id, name, admin, country_id) 
VALUES (101,	'Nellore',	'Nimisha',	21);
INSERT INTO cities(id, name, admin, country_id) 
VALUES(102,	'Tanjore',	'Pithcumani',	11);
INSERT INTO cities(id, name, admin, country_id) 
VALUES(103,	'Mumbai',	'Sana',	11);
INSERT INTO cities(id, name, admin, country_id) 
VALUES(105,	'Kollam',	'Vishak',	31);

commit; 

SET LINESIZE 500;
SET TRIMSPOOL ON;
column name format a20;
column admin format a20;

SELECT * FROM cities;

CREATE TABLE employees
(
    id NUMBER GENERATED BY DEFAULT AS IDENTITY START WITH 1 INCREMENT BY 1 PRIMARY KEY,
    name VARCHAR2(125) NOT NULL,
    job_title VARCHAR2(125) NOT NULL,
    department_id NUMBER NOT NULL,
    address VARCHAR2(1000) NOT NULL,
    city_id NUMBER NOT NULL 
);


DESC employees;

INSERT INTO employees (id, name, job_title, department_id, address, city_id)
VALUES (1,	'Athira',	'SE',	10,	'----',	101);
INSERT INTO employees (id, name, job_title, department_id, address, city_id)
VALUES (2,	'Ayisha',	'Tester',	20,	'----',	102);
INSERT INTO employees (id, name, job_title, department_id, address, city_id)
VALUES (3,	'Dhaheen',	'Analyst',	20,	'----',	103);
INSERT INTO employees (id, name, job_title, department_id, address, city_id)
VALUES (4,	'Venkatesh',	'SE',	30,	'----',	103);
INSERT INTO employees (id, name, job_title, department_id, address, city_id)
VALUES (5,	'minhaj',	'Tester',	10,	'----',	101);
INSERT INTO employees (id, name, job_title, department_id, address, city_id)
VALUES (6,	'Nayana',	'SE',	30,	'----',	104);

commit; 



SELECT * FROM employees;

ALTER TABLE employees 
ADD (salary NUMBER(8,2) DEFAULT 0 NOT NULL , 
    bonus NUMBER(8,2) DEFAULT 0 NOT NULL );
    
COMMIT;


SELECT * FROM employees;

UPDATE employees SET salary = 12000, bonus = 800 WHERE id = 1;
UPDATE employees SET salary = 8000, bonus = 3000 WHERE id = 2;
UPDATE employees SET salary = 13000, bonus = 600 WHERE id = 3;
UPDATE employees SET salary = 7000, bonus = 3800 WHERE id = 4;
UPDATE employees SET salary = 11000, bonus = 800 WHERE id = 5;
UPDATE employees SET salary = 10000, bonus = 1000 WHERE id = 6;
commit;

-- to query emp_name, city_name 

SELECT employees.name AS emp_name, cities.name AS city_name
FROM employees 
INNER JOIN cities ON employees.city_id = cities.id;

-- to query emp_name, city_name + extra employees

SELECT employees.name AS emp_name, cities.name AS city_name
FROM employees 
LEFT JOIN cities ON employees.city_id = cities.id;

-- to query emp_name, city_name + extra cities
SELECT employees.name AS emp_name, cities.name AS city_name
FROM employees 
RIGHT JOIN cities ON employees.city_id = cities.id;

-- to query emp_name, city_name + extra employees + extra cities
SELECT employees.name AS emp_name, cities.name AS city_name
FROM employees 
FULL JOIN cities ON employees.city_id = cities.id;

-- to query emp_name, city_name + extra employees + extra cities + extra countries
SELECT employees.name AS emp_name, 
    cities.name AS city_name, 
    countries.name AS country_name
FROM employees 
FULL JOIN cities ON employees.city_id = cities.id
FULL JOIN countries ON cities.country_id = countries.id;

-- to query emp_name, city_name, country_name
SELECT employees.name AS emp_name, 
    cities.name AS city_name, 
    countries.name AS country_name
FROM employees 
INNER JOIN cities ON employees.city_id = cities.id
INNER JOIN countries ON cities.country_id = countries.id;

-- to query emp_name, city_name, country_name + extra countries
SELECT employees.name AS emp_name, 
    cities.name AS city_name, 
    countries.name AS country_name
FROM employees 
INNER JOIN cities ON employees.city_id = cities.id
RIGHT JOIN countries ON cities.country_id = countries.id;

SELECT ID FROM DEPARTMENTS;
SELECT NAME FROM departments WHERE ID IN (20, 30);

SELECT name
FROM countries WHERE ID IN(11,31) ORDER BY name DESC;

