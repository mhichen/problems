#!/usr/bin/python3


#*********************************************
# Given n employees, each of which earn s_i
# dollars totalling S in compensation, what
# is a cap, sigma, on each employee's salary 
# such that the total compensation is S'? 
# Note that if s_i > sigma, then s_i = sigma, 
# but if s_i < sigma, then s_i remains the same.
#*********************************************


# salaries is the list of current employee
# salaries, while new_payroll is the S' that
# the company wants to cut the total compensation
# down to

def find_salary_cap(salaries, new_payroll):
    
    # first sort list of salaries
    sorted_salaries = sorted(salaries)
    
    n = len(sorted_salaries)
    total = 0
    
    for ind in range(n-1):
        
        total += sorted_salaries[ind]
        sigma = (new_payroll - total)/(n - ind - 1)

        # This is to make sure that the next salary
        # is not above the cap sigma.  This is
        # important because the salaries that
        # are below the cap should be kept at their
        # salary.
        
        if sigma <= sorted_salaries[ind+1]:
            return sigma


if __name__ == "__main__":
    
    
    s = [90, 30, 100, 40, 20, 70]
    s2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    s3 = [90, 30, 100, 40, 20]
    
    print(find_salary_cap(s, 210))
    print(find_salary_cap(s2, 54))
    print(find_salary_cap(s3, 210))
