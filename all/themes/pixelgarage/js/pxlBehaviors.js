/**
 * This file contains all Drupal behaviours of the pixelgarage theme.
 *
 * Created by ralph on 05.01.14.
 */

(function ($) {

    /**
     * Swaps images from black/white to colored on mouse hover.
     */
    Drupal.behaviors.hoverImageSwap = {
        attach: function () {
            // switch images on hover
            $('.pe-container .pe-item a').hover(
                function () {
                    // mouse enter
                    var $img = $(this).find('img'),
                        src = $img.attr('src');
                    $img.attr('src', src.replace('.png', '_color.png'));
                },
                function () {
                    // mouse leave
                    var $img = $(this).find('img'),
                        src = $img.attr('src');
                    $img.attr('src', src.replace('_color.png', '.png'));
                }
            );
        }
    }


})(jQuery);