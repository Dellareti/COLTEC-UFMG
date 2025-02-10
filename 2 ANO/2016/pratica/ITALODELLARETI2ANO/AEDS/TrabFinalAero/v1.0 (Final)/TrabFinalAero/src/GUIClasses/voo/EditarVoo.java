/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUIClasses.voo;

import MainClasses.Aeroporto;
import MainClasses.AllData;
import MainClasses.Aviao;
import MainClasses.DescricaoVoo;
import MainClasses.Voo;
import java.util.ArrayList;
import javax.swing.DefaultListModel;
import javax.swing.JOptionPane;

public class EditarVoo extends javax.swing.JFrame {
    AllData dados;
    DefaultListModel model = new DefaultListModel();
    static int pos=-1;

    public EditarVoo(AllData dados) {
        initComponents();
        this.dados=dados;
        ArrayList <Voo> voo = this.dados.getVoos();
        //preenche lista
        for(Voo v: voo){
            model.addElement("Voo " + v.getDescVoo().getNumeroDoVoo());
        }
        listaVoo.setModel(model);
        ModificarBt.setEnabled(false);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        opcoesAeroPart = new javax.swing.JComboBox<>();
        JSPane1 = new javax.swing.JScrollPane();
        tab1 = new javax.swing.JTable();
        dataLb = new javax.swing.JLabel();
        aeropPartLb = new javax.swing.JLabel();
        JSPane2 = new javax.swing.JScrollPane();
        tab2 = new javax.swing.JTable();
        aeropDestLb = new javax.swing.JLabel();
        opcoesAeroDest = new javax.swing.JComboBox<>();
        horarioPartTxt = new javax.swing.JTextField();
        dataTxt = new javax.swing.JTextField();
        horarioDestTxt = new javax.swing.JTextField();
        aviaoLb = new javax.swing.JLabel();
        horarioPartLb = new javax.swing.JLabel();
        opcoesAviao = new javax.swing.JComboBox<>();
        horarioDestLb = new javax.swing.JLabel();
        EditarBt = new javax.swing.JButton();
        JSPane3 = new javax.swing.JScrollPane();
        tab3 = new javax.swing.JTable();
        titulo = new javax.swing.JLabel();
        scrollPanePainel = new javax.swing.JScrollPane();
        listaVoo = new javax.swing.JList<>();
        ModificarBt = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        opcoesAeroPart.addPopupMenuListener(new javax.swing.event.PopupMenuListener() {
            public void popupMenuCanceled(javax.swing.event.PopupMenuEvent evt) {
            }
            public void popupMenuWillBecomeInvisible(javax.swing.event.PopupMenuEvent evt) {
                opcoesAeroPartPopupMenuWillBecomeInvisible(evt);
            }
            public void popupMenuWillBecomeVisible(javax.swing.event.PopupMenuEvent evt) {
            }
        });

        tab1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null}
            },
            new String [] {
                "Nome", "Código", "Cidade"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        JSPane1.setViewportView(tab1);

        dataLb.setText("Data de Part");

        aeropPartLb.setText("Aeroporto Part");

        tab2.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null}
            },
            new String [] {
                "Nome", "Código", "Cidade"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        JSPane2.setViewportView(tab2);

        aeropDestLb.setText("Aerporto Dest");

        opcoesAeroDest.addPopupMenuListener(new javax.swing.event.PopupMenuListener() {
            public void popupMenuCanceled(javax.swing.event.PopupMenuEvent evt) {
            }
            public void popupMenuWillBecomeInvisible(javax.swing.event.PopupMenuEvent evt) {
                opcoesAeroDestPopupMenuWillBecomeInvisible(evt);
            }
            public void popupMenuWillBecomeVisible(javax.swing.event.PopupMenuEvent evt) {
            }
        });

        horarioPartTxt.setText("hhmm");

        dataTxt.setText("ddmmaaaa");

        horarioDestTxt.setText("hhmm");

        aviaoLb.setText("Avião");

        horarioPartLb.setText("Horario Partida");

        opcoesAviao.addPopupMenuListener(new javax.swing.event.PopupMenuListener() {
            public void popupMenuCanceled(javax.swing.event.PopupMenuEvent evt) {
            }
            public void popupMenuWillBecomeInvisible(javax.swing.event.PopupMenuEvent evt) {
                opcoesAviaoPopupMenuWillBecomeInvisible(evt);
            }
            public void popupMenuWillBecomeVisible(javax.swing.event.PopupMenuEvent evt) {
            }
        });

        horarioDestLb.setText("Horario Chegada");

        EditarBt.setText("Editar");
        EditarBt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EditarBtActionPerformed(evt);
            }
        });

        tab3.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null}
            },
            new String [] {
                "Fabricante", "Modelo", "N. Assentos"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.Integer.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        JSPane3.setViewportView(tab3);

        titulo.setText("EDITAR VOO");

        scrollPanePainel.setViewportView(listaVoo);

        ModificarBt.setText("Modificar");
        ModificarBt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ModificarBtActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(titulo)
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(EditarBt, javax.swing.GroupLayout.PREFERRED_SIZE, 132, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(scrollPanePainel, javax.swing.GroupLayout.PREFERRED_SIZE, 156, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 34, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(dataLb)
                                        .addGap(29, 29, 29)
                                        .addComponent(dataTxt, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(aviaoLb)
                                        .addGap(59, 59, 59)
                                        .addComponent(opcoesAviao, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addComponent(ModificarBt, javax.swing.GroupLayout.PREFERRED_SIZE, 131, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                    .addComponent(aeropDestLb)
                                    .addGap(18, 18, 18)
                                    .addComponent(opcoesAeroDest, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(aeropPartLb)
                                .addGap(18, 18, 18)
                                .addComponent(opcoesAeroPart, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(39, 39, 39)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(horarioPartTxt, javax.swing.GroupLayout.PREFERRED_SIZE, 72, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(horarioPartLb))
                                .addGap(35, 35, 35)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(horarioDestLb, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(horarioDestTxt, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(JSPane1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 259, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(JSPane2, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 259, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(JSPane3, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 259, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(22, 22, 22))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(titulo)
                .addGap(1, 1, 1)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(scrollPanePainel, javax.swing.GroupLayout.PREFERRED_SIZE, 196, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(horarioPartLb)
                            .addComponent(horarioDestLb))
                        .addGap(3, 3, 3)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(dataLb)
                            .addComponent(dataTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(horarioPartTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(horarioDestTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(JSPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(aeropDestLb)
                                    .addComponent(opcoesAeroDest, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(JSPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 48, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                .addComponent(opcoesAeroPart, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(aeropPartLb)))
                        .addGap(7, 7, 7)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(JSPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap())
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(aviaoLb)
                            .addComponent(opcoesAviao, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 8, Short.MAX_VALUE)
                                .addComponent(EditarBt)
                                .addGap(25, 25, 25))
                            .addGroup(layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(ModificarBt)
                                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void opcoesAeroPartPopupMenuWillBecomeInvisible(javax.swing.event.PopupMenuEvent evt) {//GEN-FIRST:event_opcoesAeroPartPopupMenuWillBecomeInvisible
        int pos = opcoesAeroPart.getSelectedIndex();
        if(pos!=-1){
            tab1.setValueAt(dados.aeroportos.get(pos).getNome(),0,0);
            tab1.setValueAt(dados.aeroportos.get(pos).getCodigo(),0,1);
            tab1.setValueAt(dados.aeroportos.get(pos).getCidade(),0,2);
        }
    }//GEN-LAST:event_opcoesAeroPartPopupMenuWillBecomeInvisible

    private void opcoesAeroDestPopupMenuWillBecomeInvisible(javax.swing.event.PopupMenuEvent evt) {//GEN-FIRST:event_opcoesAeroDestPopupMenuWillBecomeInvisible
        int pos = opcoesAeroDest.getSelectedIndex();
        if(pos!=-1){
            tab2.setValueAt(dados.aeroportos.get(pos).getNome(),0,0);
            tab2.setValueAt(dados.aeroportos.get(pos).getCodigo(),0,1);
            tab2.setValueAt(dados.aeroportos.get(pos).getCidade(),0,2);
        }
    }//GEN-LAST:event_opcoesAeroDestPopupMenuWillBecomeInvisible

    private void opcoesAviaoPopupMenuWillBecomeInvisible(javax.swing.event.PopupMenuEvent evt) {//GEN-FIRST:event_opcoesAviaoPopupMenuWillBecomeInvisible
        int pos = opcoesAviao.getSelectedIndex();
        if(pos!=-1){
            tab3.setValueAt(dados.avioes.get(pos).getNomeDoFabricante(),0,0);
            tab3.setValueAt(dados.avioes.get(pos).getNumModelo(),0,1);
            tab3.setValueAt(dados.avioes.get(pos).getNumAssentos(),0,2);
        }
    }//GEN-LAST:event_opcoesAviaoPopupMenuWillBecomeInvisible

    private void EditarBtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EditarBtActionPerformed
        if(listaVoo.getSelectedIndex()==-1)
            JOptionPane.showMessageDialog(null,"Selecione algum voo da lista para MODIFICAR.","Erro",0);        
        else{
            Voo v = this.dados.getVoos().get(listaVoo.getSelectedIndex());
            dataTxt.setText(v.getDataDePartida());
            horarioPartTxt.setText(v.getDescVoo().getHorarioDePartida());
            horarioDestTxt.setText(v.getDescVoo().getHorarioDeChegada());

            ArrayList <Aeroporto> ap = this.dados.getAeroportos();
            opcoesAeroPart.removeAllItems();
            opcoesAeroDest.removeAllItems();

            for(Aeroporto aero:ap){
                opcoesAeroPart.addItem(aero.getCodigo());
                opcoesAeroDest.addItem(aero.getCodigo());
            }
            //Avioes
            ArrayList <Aviao> av = this.dados.getAvioes();
            opcoesAviao.removeAllItems();
            for(Aviao avi:av)
                opcoesAviao.addItem(avi.getNumModelo());
            opcoesAeroPart.setSelectedIndex(-1);
            opcoesAeroDest.setSelectedIndex(-1);
            opcoesAviao.setSelectedIndex(-1);

            ModificarBt.setEnabled(true);            
        }
    }//GEN-LAST:event_EditarBtActionPerformed

    private void ModificarBtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ModificarBtActionPerformed
        String data = dataTxt.getText();
        if(opcoesAeroPart.getSelectedIndex()==-1 || opcoesAeroDest.getSelectedIndex()==-1)
            JOptionPane.showMessageDialog(null,"Selecione os aeroportos de PARTIDA e DESTINO.","Erro",0);        
        else if(opcoesAviao.getSelectedIndex()==-1)
            JOptionPane.showMessageDialog(null,"Selecione um aviao para o voo.","Erro",0);        
        
             Voo voo = new Voo(dataTxt.getText(),
            Integer.parseInt(this.dados.buscaAviaoModel((String) opcoesAviao.getSelectedItem()).getNumAssentos()),
            new DescricaoVoo(horarioPartTxt.getText(),
            horarioDestTxt.getText(),
            opcoesAeroPart.getSelectedItem().toString(),
            opcoesAeroDest.getSelectedItem().toString()),
            dados.buscaAviaoModel(opcoesAviao.getSelectedItem().toString()));
            this.dados.voos.set(pos,voo);
            this.dados.escreverDadosVoos();
            dataTxt.setText("ddmmaaaa");
            horarioPartTxt.setText("hhmm");
            horarioDestTxt.setText("hhmm");
            opcoesAeroPart.setSelectedIndex(-1);
            opcoesAeroDest.setSelectedIndex(-1);
            opcoesAviao.setSelectedIndex(-1);
            JOptionPane.showMessageDialog(null,"Voo alterado!","Inf.",1);
    }//GEN-LAST:event_ModificarBtActionPerformed

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
            java.util.logging.Logger.getLogger(EditarVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(EditarVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(EditarVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(EditarVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new EditarVoo(null).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton EditarBt;
    private javax.swing.JScrollPane JSPane1;
    private javax.swing.JScrollPane JSPane2;
    private javax.swing.JScrollPane JSPane3;
    private javax.swing.JButton ModificarBt;
    private javax.swing.JLabel aeropDestLb;
    private javax.swing.JLabel aeropPartLb;
    private javax.swing.JLabel aviaoLb;
    private javax.swing.JLabel dataLb;
    private javax.swing.JTextField dataTxt;
    private javax.swing.JLabel horarioDestLb;
    private javax.swing.JTextField horarioDestTxt;
    private javax.swing.JLabel horarioPartLb;
    private javax.swing.JTextField horarioPartTxt;
    private javax.swing.JList<String> listaVoo;
    private javax.swing.JComboBox<String> opcoesAeroDest;
    private javax.swing.JComboBox<String> opcoesAeroPart;
    private javax.swing.JComboBox<String> opcoesAviao;
    private javax.swing.JScrollPane scrollPanePainel;
    private javax.swing.JTable tab1;
    private javax.swing.JTable tab2;
    private javax.swing.JTable tab3;
    private javax.swing.JLabel titulo;
    // End of variables declaration//GEN-END:variables
}
