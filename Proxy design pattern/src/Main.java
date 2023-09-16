public class Main {
    public static void main(String[] args) throws Exception {
        EmployeeDao employeeDao = new EmployeeDaoAccesssProxy();
        employeeDao.createEmployee("USER", "Ankit");
        employeeDao.createEmployee("ADMIN", "Ankit2");
    }
}