import java.util.ArrayList;
import java.util.List;

public class Directory implements FileSystem{
    String directoryName;
    List<FileSystem> children;
    Directory(String directoryName) {
        this.directoryName = directoryName;
        this.children = new ArrayList<>();
    }

    public void add(FileSystem node){
        this.children.add(node);
    }
    @Override
    public void ls() {
        this.children.forEach(child -> {
            System.out.println("DirectoryName: " + this.directoryName);
            child.ls();
        });
    }
}
