//
//  TempTableViewCell.swift
//  Jeevan-Rekha
//
//  Created by V UMESH KUMAR RAJU on 29/01/22.
//

import UIKit

class TempTableViewCell: UITableViewCell {

    @IBOutlet var View: UIView!
    @IBOutlet var Tempincel: UILabel!
    @IBOutlet var TempInF: UILabel!
    override func awakeFromNib() {
        super.awakeFromNib()
        self.View.layer.cornerRadius = 10
        selectionStyle = .none
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
