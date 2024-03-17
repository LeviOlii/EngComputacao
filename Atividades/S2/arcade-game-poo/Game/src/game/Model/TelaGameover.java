package game.Model;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class TelaGameover extends Tela{
	private JLabel background;
	private JPanel painel;
	private JButton voltaMenu;
	
	public TelaGameover() {
		setTitle("Game Over");
		ImageIcon ref = new ImageIcon("src//res//gameover-removebg-preview.png");
		Image fundo = ref.getImage();
		JPanel painel = new JPanel();
		//setLayout(null);
		int screenWidth = Toolkit.getDefaultToolkit().getScreenSize().width;
        int screenHeight = Toolkit.getDefaultToolkit().getScreenSize().height;
        fundo = fundo.getScaledInstance(screenWidth, screenHeight, Image.SCALE_DEFAULT);
        JLabel background = new JLabel("", ref, JLabel.CENTER);
        background.setBounds(0, 0, screenWidth, screenHeight);
        add(painel);
        painel.setSize(new Dimension(screenWidth, screenHeight));
        painel.setLayout(new BorderLayout(7,7));
		painel.setBackground(Color.black);
        painel.add(background);
        
        JButton voltaMenu = new JButton();
        voltaMenu.setOpaque(false);
        voltaMenu.setContentAreaFilled(false);
        voltaMenu.setBorderPainted(false);
        voltaMenu.setSize(new Dimension(screenWidth, screenHeight));
        
        voltaMenu.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		Tela.telaAtual = 0;
        	}
        });
        painel.add(voltaMenu);
        
        
	}
	
	/*public void paint(Graphics g) {
		
		Graphics2D graficos = (Graphics2D) g;
		
		graficos.drawImage(fundo, 0, 0, null);
		
		g.dispose();
	}*/
}
