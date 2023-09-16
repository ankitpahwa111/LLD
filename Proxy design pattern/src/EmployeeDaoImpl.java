public class EmployeeDaoImpl implements EmployeeDao{
    @Override
    public void createEmployee(String creator, String name) {
        System.out.println("Employee " + name + " created");
    }
}
