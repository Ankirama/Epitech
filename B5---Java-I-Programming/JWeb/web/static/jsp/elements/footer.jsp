<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<footer id="footer"><!--Footer-->
    <div class="footer-top">
        <div class="container">
            <div class="row">
                <div class="col-sm-2">
                    <div class="companyinfo">
                        <h2><span>e</span>-shopper</h2>
                        <p>You can buy any account type, any card and any identity.</p>
                    </div>
                </div>
                <div class="col-sm-7"></div>

                <div class="col-sm-3">
                    <div class="address">
                        <img src="/static/images/home/map.png" alt="" />
                        <p>24 rue Pasteur, 94270 Le Kremlin-Bicêtre</p>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <%--<div class="footer-widget">--%>
        <%--<div class="container">--%>
            <%--<div class="row">--%>
                <%--<div class="col-sm-2">--%>
                    <%--<div class="single-widget">--%>
                        <%--<h2>Service</h2>--%>
                        <%--<ul class="nav nav-pills nav-stacked">--%>
                            <%--<li><a href="">Online Help</a></li>--%>
                            <%--<li><a href="">Contact Us</a></li>--%>
                            <%--<li><a href="">Order Status</a></li>--%>
                            <%--<li><a href="">Change Location</a></li>--%>
                            <%--<li><a href="">FAQ’s</a></li>--%>
                        <%--</ul>--%>
                    <%--</div>--%>
                <%--</div>--%>
                <%--<div class="col-sm-2">--%>
                    <%--<div class="single-widget">--%>
                        <%--<h2>Quock Shop</h2>--%>
                        <%--<ul class="nav nav-pills nav-stacked">--%>
                            <%--<li><a href="">T-Shirt</a></li>--%>
                            <%--<li><a href="">Mens</a></li>--%>
                            <%--<li><a href="">Womens</a></li>--%>
                            <%--<li><a href="">Gift Cards</a></li>--%>
                            <%--<li><a href="">Shoes</a></li>--%>
                        <%--</ul>--%>
                    <%--</div>--%>
                <%--</div>--%>
                <%--<div class="col-sm-2">--%>
                    <%--<div class="single-widget">--%>
                        <%--<h2>Policies</h2>--%>
                        <%--<ul class="nav nav-pills nav-stacked">--%>
                            <%--<li><a href="">Terms of Use</a></li>--%>
                            <%--<li><a href="">Privecy Policy</a></li>--%>
                            <%--<li><a href="">Refund Policy</a></li>--%>
                            <%--<li><a href="">Billing System</a></li>--%>
                            <%--<li><a href="">Ticket System</a></li>--%>
                        <%--</ul>--%>
                    <%--</div>--%>
                <%--</div>--%>
                <%--<div class="col-sm-2">--%>
                    <%--<div class="single-widget">--%>
                        <%--<h2>About Shopper</h2>--%>
                        <%--<ul class="nav nav-pills nav-stacked">--%>
                            <%--<li><a href="">Company Information</a></li>--%>
                            <%--<li><a href="">Careers</a></li>--%>
                            <%--<li><a href="">Store Location</a></li>--%>
                            <%--<li><a href="">Affillate Program</a></li>--%>
                            <%--<li><a href="">Copyright</a></li>--%>
                        <%--</ul>--%>
                    <%--</div>--%>
                <%--</div>--%>
                <%--<div class="col-sm-3 col-sm-offset-1">--%>
                    <%--<div class="single-widget">--%>
                        <%--<h2>About Shopper</h2>--%>
                        <%--<form action="#" class="searchform">--%>
                            <%--<input type="text" placeholder="Your email address" />--%>
                            <%--<button type="submit" class="btn btn-default"><i class="fa fa-arrow-circle-o-right"></i></button>--%>
                            <%--<p>Get the most recent updates from <br />our site and be updated your self...</p>--%>
                        <%--</form>--%>
                    <%--</div>--%>
                <%--</div>--%>

            <%--</div>--%>
        <%--</div>--%>
    <%--</div>--%>
    <div class="footer-bottom">
        <div class="container">
            <div class="row">
                <p class="pull-left">Copyright © 2015 E-SHOPPER Inc. All rights reserved.</p>
                <p class="pull-right">Designed by <span><a target="_blank" href="http://www.themeum.com">Themeum</a></span></p>
            </div>
        </div>
    </div>

</footer><!--/Footer-->
<!-- Modal -->
<div id="messageModal" class="modal fade" role="dialog">
    <div class="modal-dialog">

        <!-- Modal content-->
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal">&times;</button>
                <h4 class="modal-title" style="color: red">Warning</h4>
            </div>
            <div class="modal-body">
                <p><c:out value="${message}" /></p>
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-default" data-dismiss="modal">Ok</button>
            </div>
        </div>

    </div>
</div>
<%@ include file="/static/jsp/JSinclude.jsp" %>

<c:if test="${message != null}">
    <script type="text/javascript">
        $(window).load(function(){
            $('#messageModal').modal('show');
        });
    </script>
</c:if>