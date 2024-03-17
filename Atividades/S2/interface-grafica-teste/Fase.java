import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;
public class Fase extends JPanel{
    


    public Fase(){

        setPreferredSize(new Dimension(1368, 768));
        setVisible(true);
        setFocusable(true);
        setBackground(Color.BLACK);
        JLabel background = new JLabel(new ImageIcon("c:/Users/verid/Documents/Pasta do Levi/Imagens/fundo.jpg"));
		background.setLayout(new FlowLayout());
        background.setText("Oi tudo bem?");
        add(background);

    }

}
