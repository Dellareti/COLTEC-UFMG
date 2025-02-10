/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUIClasses.aviao;

import MainClasses.AllData;
import MainClasses.Aviao;
import java.util.ArrayList;
import javax.swing.DefaultListModel;
import javax.swing.JOptionPane;

public class EditarAviao extends javax.swing.JFrame {
    AllData dados;
    DefaultListModel model = new DefaultListModel();
    static int pos=-1;
    public EditarAviao(AllData dados) {
        initComponents();
        this.dados=dados;
        ArrayList <Aviao> avioes = this.dados.getAvioes();
        //preenche lista
        for(Aviao av: avioes){
            model.addElement(av.getNumModelo()+" "+av.getNomeDoFabricante()+" "+av.getNumAssentos());
        }
        listaAvioes.setModel(model);
        btAtualizar.setEnabled(false);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        scrollPanePainel = new javax.swing.JScrollPane();
        listaAvioes = new javax.swing.JList<>();
        btEditar = new javax.swing.JButton();
        lbTitulo = new javax.swing.JLabel();
        lbModelo = new javax.swing.JLabel();
        lbFabricante = new javax.swing.JLabel();
        lbAssentos = new javax.swing.JLabel();
        txtModelo = new javax.swing.JTextField();
        txtFabricante = new javax.swing.JTextField();
        txtAssentos = new javax.swing.JTextField();
        btAtualizar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        scrollPanePainel.setViewportView(listaAvioes);

        btEditar.setText("Editar");
        btEditar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btEditarActionPerformed(evt);
            }
        });

        lbTitulo.setText("EDITAR AVIAO");

        lbModelo.setText("Modelo:");

        lbFabricante.setText("Fabricante:");

        lbAssentos.setText("Assentos:");

        btAtualizar.setText("Atualizar");
        btAtualizar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btAtualizarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(scrollPanePainel, javax.swing.GroupLayout.PREFERRED_SIZE, 181, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(10, 10, 10)
                                .addComponent(lbModelo)
                                .addGap(23, 23, 23)
                                .addComponent(txtModelo))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addGap(18, 49, Short.MAX_VALUE)
                                .addComponent(btAtualizar)
                                .addGap(26, 26, 26))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(12, 12, 12)
                                        .addComponent(lbFabricante))
                                    .addGroup(layout.createSequentialGroup()
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                        .addComponent(lbAssentos)))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(txtAssentos)
                                    .addComponent(txtFabricante)))))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(47, 47, 47)
                        .addComponent(lbTitulo))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(65, 65, 65)
                        .addComponent(btEditar)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(13, Short.MAX_VALUE)
                .addComponent(lbTitulo)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(18, 18, 18)
                        .addComponent(scrollPanePainel, javax.swing.GroupLayout.PREFERRED_SIZE, 191, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(46, 46, 46)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(lbModelo)
                            .addComponent(txtModelo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(lbFabricante)
                            .addComponent(txtFabricante, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(lbAssentos)
                            .addComponent(txtAssentos, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btAtualizar)))
                .addGap(18, 18, 18)
                .addComponent(btEditar)
                .addGap(23, 23, 23))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btEditarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btEditarActionPerformed
        if(listaAvioes.getSelectedIndex()!=-1){
            Aviao av = this.dados.getAvioes().get(listaAvioes.getSelectedIndex());
            txtModelo.setText(av.getNumModelo());
            txtFabricante.setText(av.getNomeDoFabricante());
            txtAssentos.setText(av.getNumAssentos());
            btAtualizar.setEnabled(true);
            pos = listaAvioes.getSelectedIndex();
        }
        else{
            JOptionPane.showMessageDialog(null,"Para editar algum aviao, clique para selecioná-lo!","Erro",0);
        }
    }//GEN-LAST:event_btEditarActionPerformed

    private void btAtualizarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btAtualizarActionPerformed
        if((txtModelo.getText().length()<0)||(txtModelo.getText().length()>20)||(txtFabricante.getText().length()<0)||(txtFabricante.getText().length()>20)||(txtAssentos.getText().length()<0)||!(txtAssentos.getText().matches("^[0-9]*$")))
            JOptionPane.showMessageDialog(null,"Existe algum campo invalido!\nModelo:0 a 20 carac.\nFabricante:0 a 20 carac.\nAssentos: numero","Erro",0);        
        else{
            Aviao av = new Aviao(txtModelo.getText(),txtFabricante.getText().toUpperCase(),txtAssentos.getText());
            this.dados.avioes.set(pos,av);
            this.dados.escreverDadosAvioes();
            txtModelo.setText("");
            txtFabricante.setText("");
            txtAssentos.setText("");
            ArrayList <Aviao> avs = this.dados.getAvioes();
            model = new DefaultListModel();
            //preenche lista
            for(Aviao a: avs){
                model.addElement(a.getNumModelo()+" "+a.getNomeDoFabricante()+" "+a.getNumAssentos());
            }
            listaAvioes.setModel(model);

            JOptionPane.showMessageDialog(null,"Dados do Aviao Atualizados!","Inf.",1);        
            btAtualizar.setEnabled(false);
            this.dados.escreverDadosAvioes();
        }
    }//GEN-LAST:event_btAtualizarActionPerformed

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
            java.util.logging.Logger.getLogger(EditarAviao.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(EditarAviao.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(EditarAviao.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(EditarAviao.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new EditarAviao(null).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btAtualizar;
    private javax.swing.JButton btEditar;
    private javax.swing.JLabel lbAssentos;
    private javax.swing.JLabel lbFabricante;
    private javax.swing.JLabel lbModelo;
    private javax.swing.JLabel lbTitulo;
    private javax.swing.JList<String> listaAvioes;
    private javax.swing.JScrollPane scrollPanePainel;
    private javax.swing.JTextField txtAssentos;
    private javax.swing.JTextField txtFabricante;
    private javax.swing.JTextField txtModelo;
    // End of variables declaration//GEN-END:variables
}
