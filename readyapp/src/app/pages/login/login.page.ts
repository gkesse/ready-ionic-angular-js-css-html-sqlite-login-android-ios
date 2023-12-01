import { Component, OnInit } from '@angular/core';
import { NavController } from '@ionic/angular';
//===============================================
@Component({
  selector: 'app-login',
  templateUrl: './login.page.html',
  styleUrls: ['./login.page.scss'],
})
//===============================================
export class LoginPage implements OnInit {

  constructor(private nav: NavController) { }

  ngOnInit() {
  }

  onLogin() {
    this.nav.navigateForward(['login-screen']);
  }

  onRegister() {
    console.log("onRegister...");
  }

  onFacebook() {
    console.log("onFacebook...");
  }

  onGoogle() {
    console.log("onGoogle...");
  }

  onApple() {
    console.log("onApple...");
  }
}
//===============================================
