package GUIClasses.voo;

import MainClasses.Aeroporto;
import MainClasses.AllData;
import MainClasses.Aviao;
import MainClasses.DescricaoVoo;
import MainClasses.Voo;
import java.util.ArrayList;
import javax.swing.DefaultListModel;
import javax.swing.JOptionPane;

public class AddVoo extends javax.swing.JFrame {
    DefaultListModel model = new DefaultListModel();
    AllData dados;
    public AddVoo(AllData dados) {
        initComponents();
        this.dados=dados;
        //Aeroportos de Partida e Chegada
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
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        titulo = new javax.swing.JLabel();
        opcoesAeroPart = new javax.swing.JComboBox<>();
        dataLb = new javax.swing.JLabel();
        aeropPartLb = new javax.swing.JLabel();
        aeropDestLb = new javax.swing.JLabel();
        opcoesAeroDest = new javax.swing.JComboBox<>();
        dataTxt = new javax.swing.JTextField();
        aviaoLb = new javax.swing.JLabel();
        opcoesAviao = new javax.swing.JComboBox<>();
        CriarVooBt = new javax.swing.JButton();
        JSPane3 = new javax.swing.JScrollPane();
        tab3 = new javax.swing.JTable();
        JSPane1 = new javax.swing.JScrollPane();
        tab1 = new javax.swing.JTable();
        JSPane2 = new javax.swing.JScrollPane();
        tab2 = new javax.swing.JTable();
        horarioPartTxt = new javax.swing.JTextField();
        horarioDestTxt = new javax.swing.JTextField();
        horarioPartLb = new javax.swing.JLabel();
        horarioDestLb = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        titulo.setText("ADICIONAR VOO");

        opcoesAeroPart.addPopupMenuListener(new javax.swing.event.PopupMenuListener() {
            public void popupMenuCanceled(javax.swing.event.PopupMenuEvent evt) {
            }
            public void popupMenuWillBecomeInvisible(javax.swing.event.PopupMenuEvent evt) {
                opcoesAeroPartPopupMenuWillBecomeInvisible(evt);
            }
            public void popupMenuWillBecomeVisible(javax.swing.event.PopupMenuEvent evt) {
            }
        });

        dataLb.setText("Data de Part");

        aeropPartLb.setText("Aeroporto Part");

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

        dataTxt.setText("ddmmaaaa");

        aviaoLb.setText("Avião");

        opcoesAviao.addPopupMenuListener(new javax.swing.event.PopupMenuListener() {
            public void popupMenuCanceled(javax.swing.event.PopupMenuEvent evt) {
            }
            public void popupMenuWillBecomeInvisible(javax.swing.event.PopupMenuEvent evt) {
                opcoesAviaoPopupMenuWillBecomeInvisible(evt);
            }
            public void popupMenuWillBecomeVisible(javax.swing.event.PopupMenuEvent evt) {
            }
        });

        CriarVooBt.setText("Criar");
        CriarVooBt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CriarVooBtActionPerformed(evt);
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

        horarioPartTxt.setText("hhmm");

        horarioDestTxt.setText("hhmm");

        horarioPartLb.setText("Horario Partida");

        horarioDestLb.setText("Horario Chegada");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addGroup(layout.createSequentialGroup()
                            .addComponent(dataLb)
                            .addGap(29, 29, 29)
                            .addComponent(dataTxt))
                        .addGroup(layout.createSequentialGroup()
                            .addComponent(aeropPartLb)
                            .addGap(18, 18, 18)
                            .addComponent(opcoesAeroPart, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addComponent(titulo)
                        .addComponent(CriarVooBt, javax.swing.GroupLayout.PREFERRED_SIZE, 171, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(aeropDestLb)
                            .addComponent(aviaoLb))
                        .addGap(22, 22, 22)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(opcoesAviao, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(opcoesAeroDest, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addGap(45, 45, 45)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(horarioPartTxt, javax.swing.GroupLayout.PREFERRED_SIZE, 72, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(horarioPartLb))
                        .addGap(35, 35, 35)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(horarioDestLb, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(horarioDestTxt)))
                    .addComponent(JSPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 259, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(JSPane1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 259, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(JSPane2, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 259, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(14, Short.MAX_VALUE)
                .addComponent(titulo)
                .addGap(1, 1, 1)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(horarioPartLb)
                    .addComponent(horarioDestLb))
                .addGap(3, 3, 3)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(dataLb)
                    .addComponent(dataTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(horarioPartTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(horarioDestTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(opcoesAeroPart, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(aeropPartLb))
                        .addGap(43, 43, 43)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(opcoesAeroDest, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(aeropDestLb)))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(JSPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(JSPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 48, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 27, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(aviaoLb)
                            .addComponent(opcoesAviao, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(34, 34, 34)
                        .addComponent(CriarVooBt))
                    .addComponent(JSPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(19, 19, 19))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void CriarVooBtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CriarVooBtActionPerformed
        //Conferir dados inseridos
        
        String data = dataTxt.getText();
        
        if(opcoesAeroPart.getSelectedIndex()==-1 || opcoesAeroDest.getSelectedIndex()==-1)
            JOptionPane.showMessageDialog(null,"Selecione os aeroportos de PARTIDA e DESTINO.","Erro",0);        
        else if(opcoesAviao.getSelectedIndex()==-1)
            JOptionPane.showMessageDialog(null,"Selecione um aviao para o voo.","Erro",0);        
        
            //Cria novo objeto de voo
            Voo voo = new Voo(dataTxt.getText(),
            Integer.parseInt(this.dados.buscaAviaoModel((String) opcoesAviao.getSelectedItem()).getNumAssentos()),
            new DescricaoVoo(horarioPartTxt.getText(),
            horarioDestTxt.getText(),
            opcoesAeroPart.getSelectedItem().toString(),
            opcoesAeroDest.getSelectedItem().toString()),
            dados.buscaAviaoModel(opcoesAviao.getSelectedItem().toString()));
            this.dados.addVoo(voo);
            this.dados.escreverDadosVoos();
            dataTxt.setText("ddmmaaaa");
            horarioPartTxt.setText("hhmm");
            horarioDestTxt.setText("hhmm");
            opcoesAeroPart.setSelectedIndex(-1);
            opcoesAeroDest.setSelectedIndex(-1);
            opcoesAviao.setSelectedIndex(-1);
            JOptionPane.showMessageDialog(null,"Novo voo adicionado !","Adicionado",1);
    }//GEN-LAST:event_CriarVooBtActionPerformed

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
            java.util.logging.Logger.getLogger(AddVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(AddVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(AddVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AddVoo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new AddVoo(null).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton CriarVooBt;
    private javax.swing.JScrollPane JSPane1;
    private javax.swing.JScrollPane JSPane2;
    private javax.swing.JScrollPane JSPane3;
    private javax.swing.JLabel aeropDestLb;
    private javax.swing.JLabel aeropPartLb;
    private javax.swing.JLabel aviaoLb;
    private javax.swing.JLabel dataLb;
    private javax.swing.JTextField dataTxt;
    private javax.swing.JLabel horarioDestLb;
    private javax.swing.JTextField horarioDestTxt;
    private javax.swing.JLabel horarioPartLb;
    private javax.swing.JTextField horarioPartTxt;
    private javax.swing.JComboBox<String> opcoesAeroDest;
    private javax.swing.JComboBox<String> opcoesAeroPart;
    private javax.swing.JComboBox<String> opcoesAviao;
    private javax.swing.JTable tab1;
    private javax.swing.JTable tab2;
    private javax.swing.JTable tab3;
    private javax.swing.JLabel titulo;
    // End of variables declaration//GEN-END:variables
}
