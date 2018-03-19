package ant.dep;

import java.io.File;
import java.io.PrintWriter;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

import org.apache.tools.ant.Task;
import org.apache.tools.ant.Project;
import org.apache.tools.ant.BuildException;

public class ChipkitTagVersion extends Task {
    String _file = null;
    String _tag = null;

    public void setFile(String d) {
        _file = d;
    }

    public void setTag(String d) {
        _tag = d;
    }

    public void execute() {
        if (_tag == null) {
            throw new BuildException("No tag specified");
        }

        if (_file == null) {
            throw new BuildException("No destination file specified");
        }

        File f = new File(_file);

        if (f.exists()) {
            f.delete();
        }


        Pattern p = Pattern.compile("-v(\\d+)\\.(\\d+)\\.(\\d+)-");
        Matcher m = p.matcher(_tag);
        if (!m.find()) {
            throw new BuildException("Tag format should be BRANCH-vA.B.C-D-HASH");
        }

        try {
            int V = Integer.parseInt(m.group(1));
            int R = Integer.parseInt(m.group(2));
            int P = Integer.parseInt(m.group(3));

            System.out.println("chipKIT Version " + String.format("%d.%d.%d", V, R, P));

            PrintWriter pw = new PrintWriter(f);
            pw.println("#ifndef _CHIPKIT_VERSION");
            pw.println("#define _CHIPKIT_VERSION");
            pw.println();
            pw.println("// Version " + _tag);
            pw.println("#define __CHIPKIT__ " + String.format("%d%02d%02d",V, R, P));
            pw.println();
            pw.println("#endif");
            pw.close();

        } catch (Exception e) {
            throw new BuildException(e.getMessage());
        }
    }
}

