//
//  ViewController.swift
//  JeevanRekha
//
//  Created by V UMESH KUMAR RAJU on 29/01/22.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var GSButton: UIButton!
    override func viewDidLoad() {
        super.viewDidLoad()
        GSButton.layer.cornerRadius = 8
        GSButton.clipsToBounds = true
    }


}

