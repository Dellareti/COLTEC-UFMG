/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUIClasses.aeroporto;

import MainClasses.Aeroporto;
import MainClasses.AllData;
import java.util.ArrayList;
import javax.swing.DefaultListModel;
import javax.swing.JOptionPane;

public class EditarAeroP extends javax.swing.JFrame {
    AllData dados;
    DefaultListModel model = new DefaultListModel();
    static int pos=-1;
    public EditarAeroP(AllData dados) {
        initComponents();
        this.dados=dados;
        ArrayList <Aeroporto> aerop = this.dados.getAeroportos();
        //preenche lista
        for(Aeroporto ap: aerop){
            model.addElement(ap.getNome()+" "+ap.getCodigo()+" "+ap.getCidade());
        }
        listaAeroP.setModel(model);
        btAtualizar.setEnabled(false);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        scrollPanePainel = new javax.swing.JScrollPane();
        listaAeroP = new javax.swing.JList<>();
        btEditar = new javax.swing.JButton();
        lbTitulo = new javax.swing.JLabel();
        lbNome = new javax.swing.JLabel();
        lbCodigo = new javax.swing.JLabel();
        lbCidade = new javax.swing.JLabel();
        txtNome = new javax.swing.JTextField();
        txtCodigo = new javax.swing.JTextField();
        txtCidade = new javax.swing.JTextField();
        btAtualizar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        scrollPanePainel.setViewportView(listaAeroP);

        btEditar.setText("Editar");
        btEditar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btEditarActionPerformed(evt);
            }
        });

        lbTitulo.setText("EDITAR AEROPORTO");

        lbNome.setText("Nome:");

        lbCodigo.setText("Código:");

        lbCidade.setText("Cidade:");

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
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                .addGroup(layout.createSequentialGroup()
                                    .addComponent(lbNome)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                    .addComponent(txtNome, javax.swing.GroupLayout.PREFERRED_SIZE, 84, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGroup(layout.createSequentialGroup()
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(lbCodigo)
                                        .addComponent(lbCidade))
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(txtCidade)
                                        .addComponent(txtCodigo))))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addComponent(btAtualizar)
                                .addGap(26, 26, 26))))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(47, 47, 47)
                        .addComponent(lbTitulo))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(65, 65, 65)
                        .addComponent(btEditar)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
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
                            .addComponent(lbNome)
                            .addComponent(txtNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(lbCodigo)
                            .addComponent(txtCodigo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(lbCidade)
                            .addComponent(txtCidade, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btAtualizar)))
                .addGap(18, 18, 18)
                .addComponent(btEditar)
                .addGap(23, 23, 23))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btEditarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btEditarActionPerformed
        if(listaAeroP.getSelectedIndex()!=-1){
            Aeroporto aerop = this.dados.getAeroportos().get(listaAeroP.getSelectedIndex());
            txtNome.setText(aerop.getNome());
            txtCodigo.setText(aerop.getCodigo());
            txtCidade.setText(aerop.getCidade());
            btAtualizar.setEnabled(true);
            pos = listaAeroP.getSelectedIndex();
        }
        else{
            JOptionPane.showMessageDialog(null,"Para editar algum aeroporto, clique para selecioná-lo!","Erro",0);
        }
    }//GEN-LAST:event_btEditarActionPerformed

    private void btAtualizarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btAtualizarActionPerformed
        if((txtNome.getText().length()<0)||(txtNome.getText().length()>20)||(txtCodigo.getText().length()!=3)||(txtCidade.getText().length()<0)||(txtCidade.getText().length()>20))
            JOptionPane.showMessageDialog(null,"Existe algum campo inválido!\nNome:0 a 20 carac.\nCódigo:3 carac.\nCidade:0 a 20 carac.","Erro",0);        
        else{
            Aeroporto aero = new Aeroporto(txtNome.getText(),txtCodigo.getText().toUpperCase(),txtCidade.getText());
            this.dados.aeroportos.set(pos,aero);
            this.dados.escreverDadosAeroportos();
            txtNome.setText("");
            txtCodigo.setText("");
            txtCidade.setText("");
            ArrayList <Aeroporto> aerop = this.dados.getAeroportos();
            model = new DefaultListModel();
            //preenche lista
            for(Aeroporto ap: aerop){
                model.addElement(ap.getNome()+" "+ap.getCodigo()+" "+ap.getCidade());
            }
            listaAeroP.setModel(model);

            JOptionPane.showMessageDialog(null,"Dados do Aeroporto Atualizados!","Inf.",1);        
            btAtualizar.setEnabled(false);
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
            java.util.logging.Logger.getLogger(EditarAeroP.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(EditarAeroP.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(EditarAeroP.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(EditarAeroP.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new EditarAeroP(null).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btAtualizar;
    private javax.swing.JButton btEditar;
    private javax.swing.JLabel lbCidade;
    private javax.swing.JLabel lbCodigo;
    private javax.swing.JLabel lbNome;
    private javax.swing.JLabel lbTitulo;
    private javax.swing.JList<String> listaAeroP;
    private javax.swing.JScrollPane scrollPanePainel;
    private javax.swing.JTextField txtCidade;
    private javax.swing.JTextField txtCodigo;
    private javax.swing.JTextField txtNome;
    // End of variables declaration//GEN-END:variables
}
