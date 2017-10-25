import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class VentanaSimple extends JFrame{
    public VentanaSimple(){
        setBounds(50,50,500,500);

        JLabel label = new JLabel("Escribe tu nombre:");
        JTextField nombre = new JTextField(20);
        JButton button = new JButton("Saludo");
        JLabel saludo = new JLabel("");

        button.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae){
                String name = nombre.getText();
                saludo.setText("Hola " + name);
            }
        });

        setLayout(new FlowLayout());
        add(label);
        add(nombre);
        add(button);
        add(saludo);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        setVisible(true);
    }
    public static void main(String[] args) {
        VentanaSimple v = new VentanaSimple();
    }
}
