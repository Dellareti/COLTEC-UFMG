/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUIClasses.cliente;

import MainClasses.AllData;
import MainClasses.Aviao;
import MainClasses.Cliente;
import MainClasses.ReservaDeViagem;
import MainClasses.ReservaDeVoo;
import MainClasses.Voo;
import java.util.ArrayList;
import javax.swing.DefaultListModel;
import javax.swing.JOptionPane;

public class IncluirVoo extends javax.swing.JFrame {
    AllData dados;
    DefaultListModel model = new DefaultListModel();
    static int pos=-1;

    public IncluirVoo(AllData dados) {
        initComponents();
        this.dados=dados;
        ArrayList <Cliente> cli = this.dados.getClientes();
        //preenche lista
        for(Cliente c: cli){
            for(ReservaDeViagem r : c.getReservasViagens())
                model.addElement(r.getNumDeViagem());
        }
        listaReservas.setModel(model);
        caixa.removeAllItems();
        for(Voo v:dados.getVoos()){
            caixa.addItem(v.getDescVoo().getNumeroDoVoo());
        }
        caixa.setSelectedIndex(-1);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jComboBox1 = new javax.swing.JComboBox<>();
        scrollPanePainel = new javax.swing.JScrollPane();
        listaReservas = new javax.swing.JList<>();
        btEditar = new javax.swing.JButton();
        lbTitulo = new javax.swing.JLabel();
        caixa = new javax.swing.JComboBox<>();
        jLabel1 = new javax.swing.JLabel();

        jComboBox1.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Item 1", "Item 2", "Item 3", "Item 4" }));

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        scrollPanePainel.setViewportView(listaReservas);

        btEditar.setText("Incluir");
        btEditar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btEditarActionPerformed(evt);
            }
        });

        lbTitulo.setText("Incluir Voo à reserva");

        jLabel1.setText("Voo");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(scrollPanePainel, javax.swing.GroupLayout.PREFERRED_SIZE, 181, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(40, 40, 40)
                                .addComponent(jLabel1))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(27, 27, 27)
                                .addComponent(caixa, javax.swing.GroupLayout.PREFERRED_SIZE, 46, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(37, 37, 37)
                        .addComponent(lbTitulo))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(55, 55, 55)
                        .addComponent(btEditar)))
                .addContainerGap(20, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(25, Short.MAX_VALUE)
                .addComponent(lbTitulo)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(18, 18, 18)
                        .addComponent(scrollPanePainel, javax.swing.GroupLayout.PREFERRED_SIZE, 191, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(72, 72, 72)
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(caixa, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(18, 18, 18)
                .addComponent(btEditar)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btEditarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btEditarActionPerformed
        ReservaDeViagem find=null;
        if(listaReservas.getSelectedIndex()!=-1){
            Aviao av = this.dados.getAvioes().get(listaReservas.getSelectedIndex());
            if(listaReservas.getSelectedValue()!=null){
                for(Cliente c:this.dados.getClientes()){
                    for(ReservaDeViagem r:c.getReservasViagens()){
                        if(r.getNumDeViagem()==Integer.parseInt(listaReservas.getSelectedValue())){
                            find = r;
                        }
                    }
                }
            }
            if(find!=null){
                ReservaDeVoo asd = new ReservaDeVoo();
                asd.getVoo().setNumVagas(asd.getVoo().getNumVagas()-1);
                asd.setVoo(this.dados.buscaVoo(caixa.getSelectedItem().toString()));
                find.getReservasDeVoos().add(asd);
                this.dados.escreverDadosClientes();
            }
        }
        else{
            JOptionPane.showMessageDialog(null,"Para adicionar algum voo a alguma viagem, selecione-o!","Erro",0);
        }
    }//GEN-LAST:event_btEditarActionPerformed

    /**
     * @param args the command line arguments
     */
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
            java.util.logging.Logger.getLogger(IncluirVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(IncluirVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(IncluirVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(IncluirVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new IncluirVoo(null).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btEditar;
    private javax.swing.JComboBox<String> caixa;
    private javax.swing.JComboBox<String> jComboBox1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel lbTitulo;
    private javax.swing.JList<String> listaReservas;
    private javax.swing.JScrollPane scrollPanePainel;
    // End of variables declaration//GEN-END:variables
}
