import javax.imageio.ImageIO;
import java.awt.image.*;
import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.LinkedList;
import java.util.List;

public class Main {
    private List path;

    private static class Room {
        public final int x, y;
        public final String name;

        public Room(String name, int x, int y) {
            this.name = name;
            this.x = x;
            this.y = y;
        }
    }

    private static class RoomLink {
        public final Room one, two;

        public RoomLink(Room one, Room two) {
            this.one = one;
            this.two = two;
        }
    }

    public static void main(String[] args) {
        //Create black image
        BufferedImage image = new BufferedImage(5120, 2880, BufferedImage.TYPE_INT_RGB);
        Graphics2D graphics = image.createGraphics();
        graphics.setBackground(Color.BLACK);

        java.util.List<Room> rooms = new LinkedList<Room>();
        java.util.List<RoomLink> links = new LinkedList<RoomLink>();
        java.util.List<java.util.List<Room>> paths = new LinkedList<java.util.List<Room>>();
        Random random = new Random();
        try {
            BufferedReader reader = new BufferedReader(new FileReader(new File("output.txt")));
            String line;
            while ((line = reader.readLine()) != null) {
                if (!line.contains("-")) {
                    String[] split = line.split(" ");
                    rooms.add(new Room(split[0], random.nextInt(5120), random.nextInt(2880)));
                } else {
                    String[] split = line.split("-");
                    Room one = null, two = null;
                    for (Room r : rooms) {
                        if (r.name.equals(split[0]))
                            one = r;
                        if (r.name.equals(split[1]))
                            two = r;
                    }
                    links.add(new RoomLink(one, two));
                }
            }
            reader.close();

            BufferedReader pathReader = new BufferedReader(new FileReader(new File("paths.txt")));
            java.util.List<Room> path = new ArrayList<Room>();
            paths.add(path);
            while ((line = pathReader.readLine()) != null) {
                if (line.equals("~~~")) {
                    path = new ArrayList<Room>();
                    paths.add(path);
                } else {
                    for (Room r : rooms) {
                        if (r.name.equals(line))
                            path.add(r);
                    }
                }
            }

            graphics.setColor(Color.WHITE);
            for (RoomLink l : links) {
                graphics.drawLine(l.one.x, l.one.y, l.two.x, l.two.y);
            }

            for (java.util.List<Room> p : paths) {
                graphics.setColor(new Color(random.nextInt(255), random.nextInt(255), random.nextInt(255)));
                Room last = p.get(0);
                for (int i = 1; i < p.size(); i++) {
                    graphics.drawLine(last.x, last.y, p.get(i).x, p.get(i).y);
                    last = p.get(i);
                }
            }

            graphics.setColor(Color.RED);
            for (Room r : rooms) {
                graphics.fillOval(r.x - 5, r.y - 5, 10, 10);
            }
            ImageIO.write(image, "png", new File("out.png"));
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
    }
}
