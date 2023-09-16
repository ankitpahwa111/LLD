public class EmployeeDaoLoggingProxy implements EmployeeDao{
    EmployeeDaoImpl employeeDao;

    public EmployeeDaoLoggingProxy() {
        this.employeeDao = new EmployeeDaoImpl();
    }

    @Override
    public void createEmployee(String creator,String employeeName) {
        System.out.println("Log: Employee being created : " + employeeName);
        employeeDao.createEmployee(creator, employeeName);
    }
}
