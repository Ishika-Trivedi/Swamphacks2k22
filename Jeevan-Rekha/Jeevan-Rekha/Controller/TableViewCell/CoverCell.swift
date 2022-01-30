//
//  CoverCell.swift
//  Jeevan-Rekha
//
//  Created by V UMESH KUMAR RAJU on 29/01/22.
//

import UIKit

class CoverCell: UITableViewCell {

    @IBOutlet var coverImage: UIImageView!
    override func awakeFromNib() {
        super.awakeFromNib()
        self.selectionStyle = .none
        coverImage.layer.cornerRadius = 10
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
