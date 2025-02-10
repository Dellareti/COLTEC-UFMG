package GUIClasses.aeroporto;

import MainClasses.Aeroporto;
import MainClasses.AllData;
import java.util.ArrayList;
import javax.swing.DefaultListModel;
import javax.swing.JOptionPane;

public class RemAeroP extends javax.swing.JFrame {
    AllData dados;
    DefaultListModel model = new DefaultListModel();
    
    public RemAeroP(AllData dados) {
        initComponents();
        this.dados=dados;
        ArrayList <Aeroporto> aerop = this.dados.getAeroportos();
        //preenche lista
        for(Aeroporto ap: aerop){
            model.addElement(ap.getNome()+" "+ap.getCodigo()+" "+ap.getCidade());
        }
        listaAeroP.setModel(model);
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        scrollPanePainel = new javax.swing.JScrollPane();
        listaAeroP = new javax.swing.JList<>();
        btRemover = new javax.swing.JButton();
        lbTitulo = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        scrollPanePainel.setViewportView(listaAeroP);

        btRemover.setText("Remover");
        btRemover.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btRemoverActionPerformed(evt);
            }
        });

        lbTitulo.setText("REMOVER AEROPORTO");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(scrollPanePainel, javax.swing.GroupLayout.PREFERRED_SIZE, 271, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(88, 88, 88)
                        .addComponent(lbTitulo))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(105, 105, 105)
                        .addComponent(btRemover)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(13, Short.MAX_VALUE)
                .addComponent(lbTitulo)
                .addGap(18, 18, 18)
                .addComponent(scrollPanePainel, javax.swing.GroupLayout.PREFERRED_SIZE, 191, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(btRemover)
                .addGap(23, 23, 23))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btRemoverActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btRemoverActionPerformed
        if(listaAeroP.getSelectedIndex()!=-1){
            int dialogButton = JOptionPane.YES_NO_OPTION;
            int dialogResult = JOptionPane.showConfirmDialog(this, "Deseja mesmo remover o aeroporto "+ dados.getAeroportos().get(listaAeroP.getSelectedIndex()).getNome()+" ?", "Confirme", dialogButton);
            if(dialogResult == 0) {
                JOptionPane.showMessageDialog(null,"Este Aeroporto foi removido!","Inf.",1);        
                dados.removeAeroP(listaAeroP.getSelectedIndex());
                model.removeElementAt(listaAeroP.getSelectedIndex());
                dados.escreverDadosAeroportos();
            }
            else {
                JOptionPane.showMessageDialog(null,"Operação Cancelada!","Inf.",1);        
            } 
        }
        else{
            JOptionPane.showMessageDialog(null,"Para remover algum aeroporto, clique para selecioná-lo!","Erro",0);        
        }
    }//GEN-LAST:event_btRemoverActionPerformed

    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(RemAeroP.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(RemAeroP.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(RemAeroP.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(RemAeroP.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new RemAeroP(null).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btRemover;
    private javax.swing.JLabel lbTitulo;
    private javax.swing.JList<String> listaAeroP;
    private javax.swing.JScrollPane scrollPanePainel;
    // End of variables declaration//GEN-END:variables
}
