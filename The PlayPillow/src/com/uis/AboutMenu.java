package com.uis;

import com.view.Menu;

/**
 * This class displays some information to the user about this program and does
 * very little on actually coding.
 *
 * @author Casper
 */
public class AboutMenu extends Menu {

    // The menu object to return to.
    private MainMenu mMenu;

    /**
     * Creates new form AboutMenu. Meant for debugging.
     */
    public AboutMenu() {
        initComponents();
        setScreen();
        mMenu = null;
    }

    /**
     * Creates new form AboutMenu with initializing the previous screen.
     *
     * @param m the menu object you are comming from.
     */
    public AboutMenu(MainMenu m) {
        initComponents();
        mMenu = m;
        setScreen();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("The PlayPillow 1.0 - About");
        setResizable(false);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel8.setFont(new java.awt.Font("Kristen ITC", 0, 14)); // NOI18N
        jLabel8.setText("<html>The PlayPillow is gemaakt in opdracht van <b>Jason Dent</b> van het bedrijf <b>Street Side Software</b>. ");
        getContentPane().add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(60, 250, -1, -1));

        jLabel9.setFont(new java.awt.Font("Kristen ITC", 0, 14)); // NOI18N
        jLabel9.setText("Het product The PlayPillow");
        getContentPane().add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(730, 250, -1, -1));

        jLabel10.setFont(new java.awt.Font("Kristen ITC", 0, 14)); // NOI18N
        jLabel10.setText(" is bedoeld om kinderen tussen 2 en 4 jaar oud te kunnen vermaken.");
        getContentPane().add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(60, 270, -1, -1));

        jPanel1.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jPanel1.setOpaque(false);

        jLabel3.setFont(new java.awt.Font("Kristen ITC", 1, 11)); // NOI18N
        jLabel3.setText("Auteur: ");

        jLabel1.setFont(new java.awt.Font("Kristen ITC", 1, 11)); // NOI18N
        jLabel1.setText("Versie:");

        jLabel5.setFont(new java.awt.Font("Kristen ITC", 1, 11)); // NOI18N
        jLabel5.setText("Productie datum:");

        jLabel6.setFont(new java.awt.Font("Kristen ITC", 1, 11)); // NOI18N
        jLabel6.setText("ITopia");

        jLabel12.setFont(new java.awt.Font("Kristen ITC", 1, 11)); // NOI18N
        jLabel12.setText("1.0");

        jLabel7.setFont(new java.awt.Font("Kristen ITC", 1, 11)); // NOI18N
        jLabel7.setText("29-05-2012");

        jLabel13.setFont(new java.awt.Font("Kristen ITC", 1, 11)); // NOI18N
        jLabel13.setText("Opdrachtgever:");

        jLabel14.setFont(new java.awt.Font("Kristen ITC", 1, 11)); // NOI18N
        jLabel14.setText("Jason Dent (Street Side Software)");

        jLabel4.setText("<html><i>ITopia is onderdeel van de Hogeschool van Amsterdam");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel3)
                            .addComponent(jLabel1)
                            .addComponent(jLabel5)
                            .addComponent(jLabel13))
                        .addGap(18, 18, 18)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel14)
                            .addComponent(jLabel6)
                            .addComponent(jLabel12)
                            .addComponent(jLabel7)))
                    .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(44, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(jLabel6))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel13)
                    .addComponent(jLabel14))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel12))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(jLabel7))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 17, Short.MAX_VALUE)
                .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        getContentPane().add(jPanel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 380, -1, 130));

        jButton1.setFont(new java.awt.Font("Kristen ITC", 0, 24)); // NOI18N
        jButton1.setText("Help");
        jButton1.setMaximumSize(new java.awt.Dimension(109, 41));
        jButton1.setMinimumSize(new java.awt.Dimension(109, 41));
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1, new org.netbeans.lib.awtextra.AbsoluteConstraints(800, 390, 120, 54));

        jButton2.setFont(new java.awt.Font("Kristen ITC", 0, 24)); // NOI18N
        jButton2.setText("Terug");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton2, new org.netbeans.lib.awtextra.AbsoluteConstraints(800, 460, 120, 54));

        jLabel2.setFont(new java.awt.Font("Kristen ITC", 0, 14)); // NOI18N
        jLabel2.setText("Dit programma is bedoeld voor het veranderen van de modi van The PlayPillow, zodat uw kind uren plezier kan beleven!");
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(60, 290, -1, -1));

        jLabel15.setIcon(new javax.swing.ImageIcon(getClass().getResource("/com/resources/GUIMenu.jpg"))); // NOI18N
        getContentPane().add(jLabel15, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * Show the help upload menu.
     *
     * @param evt of the user
     */
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        new HelpMenu(this).setVisible(true);
        dispose();
    }//GEN-LAST:event_jButton1ActionPerformed

    /**
     * Get you back to the mainmenu.
     *
     * @param evt of the user
     */
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        // TODO add your handling code here:
        mMenu.setVisible(true);
        dispose();
    }//GEN-LAST:event_jButton2ActionPerformed
//
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}
