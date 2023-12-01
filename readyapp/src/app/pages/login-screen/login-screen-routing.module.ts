import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { LoginScreenPage } from './login-screen.page';

const routes: Routes = [
  {
    path: '',
    component: LoginScreenPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class LoginScreenPageRoutingModule {}
