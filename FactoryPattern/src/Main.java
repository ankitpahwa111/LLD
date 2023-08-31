public class Main {
    public static void main(String[] args) {
        Shape shape = new shapeFactory().getShape("RECTANGLE");
        shape.draw();
    }
}