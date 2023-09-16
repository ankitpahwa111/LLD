public class EmployeeDaoAccesssProxy implements EmployeeDao{
    EmployeeDaoLoggingProxy employeeDaoLoggingProxy;
    EmployeeDaoAccesssProxy() {
        this.employeeDaoLoggingProxy = new EmployeeDaoLoggingProxy();
    }
    @Override
    public void createEmployee(String creator,String employeeName) throws Exception {
        if(creator=="USER") {
            throw new Exception("Access Denied");
        }
        if(creator=="ADMIN") {
            employeeDaoLoggingProxy.createEmployee(creator, employeeName);
        }
    }
}
