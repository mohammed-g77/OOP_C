package Hexa;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class Hexadecima extends JFrame implements ActionListener {

    private JButton conv, cancel;
    private JLabel l1, ans;
    private JTextField num;

    private void hi() {
        conv = new JButton("conv");
        cancel = new JButton("cancel");
        ans = new JLabel("in Hexa");
        l1 = new JLabel("Enter a value :");
        num = new JTextField(10);
        conv.setText("convert");
        ans.setText("in Hexa :");

        
        JPanel S = new JPanel();  
        add(S, BorderLayout.SOUTH);

        S.add(conv);
        S.add(cancel);

        JPanel N = new JPanel();
        N.setBorder(BorderFactory.createTitledBorder("Enter a number and convert to Hexa"));
        add(N, BorderLayout.NORTH);

        N.add(l1);
        N.add(num);

        add(ans, BorderLayout.CENTER);

      

        cancel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });

        conv.addActionListener(this);  
    }

    public Hexadecima() {
        super();
        setTitle("Hexadecimal");

        hi();

        conv.setForeground(Color.red);

        setBounds(200, 200, 500,400);

        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == conv) {
            String t = num.getText();

            try {
                int number = Integer.parseInt(t);
                if(number>0){
                String Res = Integer.toHexString(number);
                ans.setText("in Hexa : " + Res.toUpperCase());
                
                }else ans.setText("non : ");
            } catch (NumberFormatException ex) {
                ans.setText("Invalid Input");
            }
        } else if (e.getSource() == cancel) {
            dispose();
        }
    }

    public static void main(String[] args) {
        new Hexadecima();
    }
}
