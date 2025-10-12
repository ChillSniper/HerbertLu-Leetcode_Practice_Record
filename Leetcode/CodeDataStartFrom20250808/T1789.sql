# 这个得用子查询
select
    employee_id,
    department_id
from
    employee
where
    department_id = 'Y'
    or employee_id in (
        select
            employee_id
        from
            employee
        GROUP BY
            employee_id
        having
            count(*) = 1
    );