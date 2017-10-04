<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html lang="en">
<head>
	<%@ include file="/static/jsp/headInclude.jsp" %>
</head><!--/head-->

<body>

	<%@ include file="/static/jsp/elements/header.jsp" %>
	<section id="form"><!--form-->
		<div class="container">
			<div class="row">
				<div class="col-sm-4 col-sm-offset-1">
					<div class="login-form"><!--login form-->
						<h2>Login to your account</h2>
						<form action="login" method="POST">
							<input type="text" placeholder="Username" name="signinUsername" required/>
							<input type="password" placeholder="Password" name="signinPassword" required/>
							<%--<span>--%>
								<%--<input type="checkbox" class="checkbox" name="signinKeep">--%>
								<%--Keep me signed in--%>
							<%--</span>--%>
							<button type="submit" name="signin" value="Signin" class="btn btn-default">Login</button>
						</form>
					</div><!--/login form-->
				</div>
				<div class="col-sm-1">
					<h2 class="or">OR</h2>
				</div>
				<div class="col-sm-4">
					<div class="signup-form"><!--sign up form-->
						<h2>New User Signup!</h2>
						<form action="login" method="POST">
							<input type="text" placeholder="Username" name="signupUser" required/>
							<input type="email" placeholder="Email Address" name="signupEmail" required/>
							<input type="password" placeholder="Password" name="signupPassword" required/>
							<button type="submit" name="signup" value="Signup" class="btn btn-default">Signup</button>
						</form>
					</div><!--/sign up form-->
				</div>
			</div>
		</div>
	</section><!--/form-->
	<%@ include file="/static/jsp/elements/footer.jsp" %>
	<%@ include file="/static/jsp/JSinclude.jsp" %>

</body>
</html>