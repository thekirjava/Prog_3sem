package com.company;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonSyntaxException;
import com.google.gson.reflect.TypeToken;
import com.google.gson.stream.JsonReader;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.labels.PieSectionLabelGenerator;
import org.jfree.chart.labels.StandardPieSectionLabelGenerator;
import org.jfree.chart.plot.PiePlot;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.AttributedString;
import java.text.DecimalFormat;
import java.util.*;
import java.util.List;
import java.util.Timer;

public class MainWindow extends JFrame {

    static class ParsedData {
        String name;
        double value;
    }

    static class LegendCell {
        public LegendCell(Color chartColor, String name) {
            this.chartColor = chartColor;
            this.name = name;
        }

        Color chartColor;
        String name;

        public Color getChartColor() {
            return chartColor;
        }

        public String getName() {
            return name;
        }
    }

    class ChartLegendRenderer extends JLabel implements ListCellRenderer {
        public Component getListCellRendererComponent(JList list, Object value, int index, boolean isSelected, boolean cellHasFocus) {
            LegendCell entry = (LegendCell) value;
            setText(entry.getName());
            BufferedImage image = new BufferedImage(50, 50, BufferedImage.TYPE_INT_ARGB);
            Graphics2D graphics2D = image.createGraphics();
            graphics2D.setPaint(entry.getChartColor());
            graphics2D.fillRect(0, 0, 50, 50);
            ImageIcon icon = new ImageIcon(image);
            setIcon(icon);
            if (isSelected) {
                setBackground(list.getSelectionBackground());
                setForeground(list.getSelectionForeground());
            } else {
                setBackground(list.getBackground());
                setForeground(list.getForeground());
            }
            setEnabled(list.isEnabled());
            setFont(list.getFont());
            setOpaque(true);
            return this;
        }
    }

    MainWindow() {
        this.setBounds(100, 100, 1100, 700);
        this.setTitle("Lab4");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel task1 = new JPanel();
        JPanel task2 = new JPanel();
        JPanel task3 = new JPanel();
        task1.setLayout(new BorderLayout());
        task2.setLayout(new BorderLayout());
        task3.setLayout(new BorderLayout());
        DrawingPanel draw1 = new DrawingPanel(310, 310);
        DrawingPanel draw2 = new DrawingPanel(Toolkit.getDefaultToolkit().getScreenSize().width, Toolkit.getDefaultToolkit().getScreenSize().height);
        task1.add(draw1, BorderLayout.CENTER);
        task2.add(draw2, BorderLayout.CENTER);

        JTabbedPane tabbedPane = new JTabbedPane();
        Timer timer = new Timer();
        TimerTask clock = new TimerTask() {
            private void draw(Graphics graphics, Graphics graphicsBuffer) {
                double x = 150 + 150 * Math.cos(angle1);
                double y = 150 + 150 * Math.sin(angle1);
                graphics.drawLine(150, 150, (int) x, (int) y);
                graphicsBuffer.drawLine(150, 150, (int) x, (int) y);
            }

            @Override
            public void run() {
                if (tabbedPane.getSelectedIndex() == 0) {
                    Graphics graphics = draw1.getGraphics();
                    Graphics graphicsBuffer = draw1.getBuffer().getGraphics();
                    penColor = Color.WHITE;
                    graphics.setColor(penColor);
                    graphicsBuffer.setColor(penColor);
                    draw(graphics, graphicsBuffer);
                    angle1 += Math.PI / 30;
                    if (angle1 >= 2 * Math.PI) {
                        angle1 = 0;
                    }
                    penColor = Color.BLACK;
                    graphics.setColor(penColor);
                    graphicsBuffer.setColor(penColor);
                    draw(graphics, graphicsBuffer);
                    draw1.repaint();
                }
            }
        };
        TimerTask init = new TimerTask() {
            @Override
            public void run() {
                Graphics graphics = draw1.getGraphics();
                Graphics graphicsBuffer = draw1.getBuffer().getGraphics();
                penColor = Color.WHITE;
                graphics.setColor(penColor);
                graphicsBuffer.setColor(penColor);
                graphics.fillRect(0, 0, 300, 300);
                graphicsBuffer.fillRect(0, 0, 300, 300);
                penColor = Color.BLACK;
                graphics.setColor(penColor);
                graphicsBuffer.setColor(penColor);
                graphics.drawOval(0, 0, 300, 300);
                graphicsBuffer.drawOval(0, 0, 300, 300);
                tabbedPane.setEnabled(true);
            }
        };
        timer.schedule(init, 2000);
        timer.schedule(clock, 2050, 1000);


        JSlider speed = new JSlider(1, 20, 10);
        JRadioButton clockwise = new JRadioButton("Clockwise", true);
        JRadioButton counterClockwise = new JRadioButton("Counter clockwise");
        ButtonGroup directions = new ButtonGroup();
        directions.add(clockwise);
        directions.add(counterClockwise);
        JButton load = new JButton("Load picture");
        load.addActionListener(e -> {
            JFileChooser fileChooser = new JFileChooser(".");
            fileChooser.setFileFilter(new FileNameExtensionFilter("Images", "jpg", "jpeg", "png", "bmp"));
            if (fileChooser.showDialog(MainWindow.this, "Load") == JFileChooser.APPROVE_OPTION) {
                try {
                    draw2.loadImage(ImageIO.read(fileChooser.getSelectedFile()));
                } catch (IOException exc) {
                    JOptionPane.showMessageDialog(MainWindow.this, "File doesn't exist", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
        TimerTask runningPicture = new TimerTask() {
            @Override
            public void run() {
                int w = MainWindow.this.getWidth();
                int h = MainWindow.this.getHeight();
                if ((draw2.getMovingPicture() != null) && (tabbedPane.getSelectedIndex() == 1)) {
                    Graphics graphics = draw2.getGraphics();
                    Graphics graphicsBuffer = draw2.getBuffer().getGraphics();
                    penColor = Color.WHITE;
                    graphics.setColor(penColor);
                    graphicsBuffer.setColor(penColor);
                    graphics.fillRect(0, 0, w, h);
                    graphicsBuffer.fillRect(0, 0, w, h);
                    penColor = Color.BLACK;
                    graphics.setColor(penColor);
                    graphicsBuffer.setColor(penColor);
                    double radius = Double.min(w / 2, h / 2) - 100;
                    double x = w / 2 + radius * Math.cos(angle2);
                    double y = h / 2 + radius * Math.sin(angle2);

                    graphics.drawImage(draw2.getMovingPicture(), (int) x, (int) y, null);
                    graphicsBuffer.drawImage(draw2.getMovingPicture(), (int) x, (int) y, null);
                    double delta = Math.PI / 180 * speed.getValue();
                    if (counterClockwise.isSelected()) {
                        delta *= -1;
                    }
                    angle2 += delta;
                    draw2.repaint();
                }
            }
        };
        timer.schedule(runningPicture, 2050, 1000);
        task2.add(speed, BorderLayout.SOUTH);
        JPanel buttonPane = new JPanel();
        buttonPane.setLayout(new GridLayout(3, 1));
        buttonPane.add(clockwise);
        buttonPane.add(counterClockwise);
        buttonPane.add(load);
        task2.add(buttonPane, BorderLayout.EAST);
        JButton jsonOpen1 = new JButton("Open");
        DefaultPieDataset pieDataset = new DefaultPieDataset();
        jsonOpen1.addActionListener(e -> {
            try {
                JFileChooser fileChooser = new JFileChooser();
                fileChooser.setCurrentDirectory(new File("."));
                fileChooser.setFileFilter(new FileNameExtensionFilter("JSON files", "json"));
                if (fileChooser.showDialog(MainWindow.this, "Open") == JFileChooser.APPROVE_OPTION) {
                    GsonBuilder builder = new GsonBuilder();
                    Gson gson = builder.create();
                    JsonReader reader = new JsonReader(new FileReader(fileChooser.getSelectedFile()));
                    ArrayList<ParsedData> jsonParsed;
                    jsonParsed = gson.fromJson(reader, new TypeToken<List<ParsedData>>() {
                    }.getType());
                    pieDataset.clear();
                    for (ParsedData parsedData : jsonParsed) {
                        pieDataset.setValue(parsedData.name, parsedData.value);
                    }
                }
            } catch (FileNotFoundException ex) {
                JOptionPane.showMessageDialog(MainWindow.this, "File doesn't exist", "Error", JOptionPane.ERROR_MESSAGE);
            } catch (JsonSyntaxException ex) {
                JOptionPane.showMessageDialog(MainWindow.this, "Incorrect JSON file", "Error", JOptionPane.ERROR_MESSAGE);

            }
        });
        JFreeChart chart = ChartFactory.createPieChart("Chart", pieDataset, true, true, false);
        PieSectionLabelGenerator generator = new StandardPieSectionLabelGenerator("{0}: {1} ({2})", new DecimalFormat("0"), new DecimalFormat("0%"));
        PiePlot plot = (PiePlot) chart.getPlot();
        plot.setLabelGenerator(generator);
        ChartPanel pane = new ChartPanel(chart);
        task3.add(pane, BorderLayout.CENTER);
        task3.add(jsonOpen1, BorderLayout.SOUTH);
        tabbedPane.add("Task 1", task1);
        tabbedPane.add("Task 2", task2);
        tabbedPane.add("Task 3", task3);
        tabbedPane.setEnabled(false);
        Container container = this.getContentPane();
        container.setLayout(new BorderLayout());
        container.add(tabbedPane, BorderLayout.CENTER);
    }

    Color penColor = Color.BLACK;
    double angle1 = 3 * Math.PI / 2;
    double angle2 = 3 * Math.PI / 2;
    double angle3 = 0;
}