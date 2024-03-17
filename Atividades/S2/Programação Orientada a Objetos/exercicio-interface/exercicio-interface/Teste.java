import javax.swing.JFrame;
import javax.swing.event.MouseInputListener;

import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;


public class Teste extends JFrame implements MouseMotionListener, MouseInputListener {
    
    public Teste(){
        addMouseListener(this);
        setSize(1360, 768); 
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        addMouseMotionListener(this);
        setLocationRelativeTo(null);
    }
    
    public void mouseDragged(MouseEvent e)
    {
        /*System.out.println("X = " + e.getClickCount());
        System.out.println("Y = " + e.getY());
    }
    public void mouseMoved(MouseEvent e)
    {
        /*System.out.println("X = " + e.getClickCount());
        System.out.println("X = " + e.getX());
        System.out.println("Y = " + e.getY());*/
    }

    public void mouseClicked(MouseEvent e)
    {
        System.out.println("X = " + e.getX());
        System.out.println("X = " + e.getY());
    }

    public void mousePressed(MouseEvent e){

    }

    public void mouseEntered(MouseEvent e){

    }

    public void mouseReleased(MouseEvent e){

    }

    public void mouseExited(MouseEvent e){

    }

    @Override
    public void mouseMoved(MouseEvent e) {
        // TODO Auto-generated method stub
        
    }


    


}
